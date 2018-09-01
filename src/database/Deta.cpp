/*
 * Deta.cpp
 *
 *  Created on: Aug 24, 2018
 *      Author: Raishin
 */

#include "Deta.h"

#include <fstream>

Deta::Deta(std::string path, std::string databasename) {
	this->path = path;
	this->databasename = databasename;

	std::string name = path + databasename;
	int rc = sqlite3_open(name.c_str(), &db);

	// if error
	if(rc) {
		sqlite3_errmsg(db);
	}

	if(!tableExist("classes")) {
		std::string command;

		// table stores command and command path. Then write it to classdata.h
		command = "CREATE TABLE classes(id INT NOT NULL PRIMARY KEY, name VARCHAR(100) NOT NULL UNIQUE, path VARCHAR(100) NOT NULL)";
		this->exec(command.c_str());

		command = "CREATE TABLE classes_amount(id INT NOT NULL PRIMARY KEY, amount INT NOT NULL)";
		this->exec(command.c_str());

		// start with zero command
		command = "INSERT INTO classes_amount(id, amount) VALUES (1, 0)";
		this->exec(command.c_str());
	}


}

Deta::~Deta() {
	sqlite3_close(db);
	/*dropDatabase();*/
}


/*
 * PRIVATE METHOD
 */
void Deta::exec(const char* command) {
	if(sqlite3_exec(db, command, NULL, NULL, NULL)) {
		std::cout << command << "\n";
		std::cout << sqlite3_errmsg(db) << "\n";
		throw std::string("sql error");
	}
}

/*
 * The number of command in database
 */
int Deta::sizeClass() {
	sqlite3_stmt *stmt;
	std::string command = "SELECT amount from classes_amount";

	sqlite3_prepare(db, command.c_str(), -1, &stmt, NULL);

	sqlite3_step(stmt);
	char *result = (char *) sqlite3_column_text(stmt, 0);
	int size = *result - 48; // result is a char, we want an int, so convert char value to int

	sqlite3_finalize(stmt);

	return size;
}

/*
 * CRUD CLASS
 */
void Deta::createClass(std::string name, std::string path) {
	int size = sizeClass();
	std::string command = "INSERT INTO classes(id, name, path) values (" + std::to_string(size + 1) + ", '" + name + "', '" + path + "')";
	this->exec(command.c_str());
	this->update("classes_amount", std::string("amount = ") + std::to_string(size), "amount=amount+1");
}

void Deta::readClass(std::vector<std::string>& names,
		std::vector<std::string>& paths) {

	sqlite3_stmt *stmt;

	int size = sizeClass();
	names.resize(size);
	paths.reserve(size);

	std::string  command = "SELECT * from classes";
	sqlite3_prepare(db, command.c_str(), -1, &stmt, NULL);
	sqlite3_step(stmt);

	for(int index = 0; sqlite3_column_text(stmt, 0) != NULL; index++) { //add until the end of the table
		names[index] = std::string((char*) sqlite3_column_text(stmt, 1));
		paths[index] = std::string((char*) sqlite3_column_text(stmt, 2));
		sqlite3_step(stmt);
	}

	sqlite3_finalize(stmt);
}

void Deta::updateClass(std::string set, std::string where) {
	std::string command = std::string("UPDATE classes SET ") + set;
	command += std::string(" WHERE ") + where;

	this->exec(command.c_str());
}

void Deta::deleteClass(std::string where) {
	std::string command = std::string("DELETE FROM classes WHERE ") + where;
	this->exec(command.c_str());
}

/*
 * WRITE COMMAND IN classdata.h
 */
void Deta::updateHeader() {
	std::vector<std::string> names;
	std::vector<std::string> paths;
	this->readClass(names, paths);

	std::string header_start =
			"#ifndef SRC_DATABASE_CLASSDATA_H_"
			"\n#define SRC_DATABASE_CLASSDATA_H_"
			"\n\n#include <iostream>"
			"\n#include <vector>"
			"\n\n#include \"../abstracts/ACommand.h\"";

	std::string header_end = "\n#endif";
	std::string header_content = "\n\nstd::vector<ACommand*> command_list = {";

	for(int x = 0; x < names.size(); x++) {
		header_content += "new " + names[x] + ", ";
		header_start += "\n#include \"" + paths[x] +"\"";
	}
	header_content = header_content.substr(0, header_content.size() - 2); // delete the last ", "
	header_content += "};\n";
	header_content = header_start + header_content + header_end;

	// write file
	std::ofstream myfile;
	myfile.open("src/database/classdata.h");
	myfile << header_content;
	myfile.close();
}

void Deta::dropDatabase() {
	/*this->exec("DETACH DATABASE main");*/
	std::string command = std::string("rm ") + path + databasename;
	system(command.c_str());
}


/*
 * CRUD FOR COMMAND
 */
void Deta::createTable(std::string column, std::string row) {
	std::string command = "CREATE TABLE " + column + "(" + row + ", id INT NOT NULL AUTOINCREMENT PRIMARY KEY)";
	this->exec(command.c_str());
}

void Deta::deleteTable(std::string column) {
	std::string command = "DROP TABLE " + column;
	this->exec(command.c_str());
}

bool Deta::tableExist(std::string column) {
	sqlite3_stmt *stmt;
	std::string command = "SELECT name FROM sqlite_master WHERE type='table' AND name='" + column + "'";

	sqlite3_prepare( db, command.c_str(), -1, &stmt, NULL );
	sqlite3_step(stmt);

	bool exist = !(sqlite3_column_text(stmt, 0) == NULL);

	sqlite3_finalize(stmt);
	return exist;

}


/*
 * CRUD TO TABLE
 */
void Deta::insert(std::string column, std::string field_name, std::string values) {
	std::string command = "INSERT INTO " + column + " (" + field_name + ") VALUES (" + values + ")";
	this->exec(command.c_str());
}

void Deta::update(std::string column, std::string old_row,
		std::string new_row) {
	std::string command = "UPDATE " + column + " SET " + new_row + " WHERE " + old_row;
	this->exec(command.c_str());
}

sqlite3_stmt* Deta::read(std::string column, std::string values) {
	std::string command = std::string("SELECT * FROM ") + column;
	command += std::string(" WHERE ") + values;

	sqlite3_stmt *stmt;
	sqlite3_prepare(db, command.c_str(), -1, &stmt, NULL);

	return stmt;
}

sqlite3_stmt* Deta::readAll(std::string column) {
	std::string command = std::string("SELECT * FROM ") + column;

	sqlite3_stmt *stmt;
	sqlite3_prepare(db, command.c_str(), -1, &stmt, NULL);

	return stmt;

}

void Deta::remove(std::string column, std::string row) {
	std::string command = "DELETE FROM " + column + " WHERE " + row;
	this->exec(command.c_str());
}
