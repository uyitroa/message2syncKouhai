/*
 * Deta.cpp
 *
 *  Created on: Aug 24, 2018
 *      Author: Raishin
 */

#include "Deta.h"

#include <iostream>
#include <fstream>

#include <cppconn/exception.h>
#include <cppconn/prepared_statement.h>
/*
#include "../../lib/cppconn/exception.h"
#include "../../lib/cppconn/resultset.h"
#include "../../lib/cppconn/statement.h"
#include "../../lib/cppconn/prepared_statement.h"
*/

Deta::Deta(std::string address, std::string name, std::string password) {
	this->driver = get_driver_instance();
	this->con = driver->connect(address, name, password);
	this->stmt = this->con->createStatement();
	try {
		con->setSchema(this->DATABASENAME);
		std::cout << "Connected" << "\n";

	} catch (sql::SQLException &e) {
		// if the database is not created
		if(e.what() == this->NODATABASE) {
			stmt->execute("CREATE DATABASE " + this->DATABASENAME);
			con->setSchema(this->DATABASENAME);
			stmt->execute("CREATE TABLE classes (id INT NOT NULL AUTO_INCREMENT, name VARCHAR(40) UNIQUE, path VARCHAR(200), created DATE, PRIMARY KEY(id))");

			// check if column amount exist for readClass, which need a vector, and if we know already the amount, no need for push_back();
			stmt->execute("CREATE TABLE classes_amount (id INT NOT NULL AUTO_INCREMENT, amount INT, PRIMARY KEY(id))");
			stmt->execute("INSERT INTO classes_amount (amount) VALUES (0)");
		} else {
			std::cout << "ERROR " << e.what() << "\n";
		}
	}

}

Deta::~Deta() {
	std::cout << "Deleting deta" << "\n";
	delete this->con;
	delete this->stmt;
}

void Deta::createClass(std::string name, std::string path) {
	try {
		stmt->execute("INSERT INTO classes (name, path, created) VALUES ('" + name + "', '" + path + "', NOW())");
		this->updateClass("classes_amount", "amount = amount + 1", "id = 1");
	} catch (sql::SQLException &e) {
		std::cout << name << " already exists" << "\n";
	}
}

void Deta::readClass(std::vector<std::string>& names,
	std::vector<std::string>& paths) {
	sql::ResultSet *res;

	res = stmt->executeQuery("SELECT amount from classes_amount");
	res->next();
	int size = 0;
	size = res->getInt(1);

	names.resize(size);
	paths.resize(size);
/*	std::cout << size << "\n";*/

	sql::ResultSet *result_set = stmt->executeQuery("SELECT * from classes");
	int index = 0;
	while(result_set->next()) {
		names[index] = result_set->getString(2);
		paths[index] = result_set->getString(3);
		std::cout << names[index] << "\n";
		index++;
	}

	delete res;
	delete result_set;
}

void Deta::updateClass(std::string table, std::string set, std::string where) {
	stmt->execute("UPDATE " + table + " SET " + set + " WHERE " + where);
}

void Deta::deleteClass(std::string table, std::string where) {
	stmt->execute("DELETE FROM " + table + " WHERE " + where);
}

/* write all class in header classdata.h
 * to store class data */
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
	stmt->execute("DROP DATABASE " + this->DATABASENAME);
}


void Deta::createColumn(std::string column, std::string row) {
	stmt->execute("CREATE TABLE " + column + "(id INT NOT NULL AUTO_INCREMENT, " + row + ", PRIMARY KEY (id))");
}
void Deta::deleteColumn(std::string column) {
	stmt->execute("DROP TABLE " + column);
}


bool Deta::columnExist(std::string column) {
	sql::ResultSet *res = stmt->executeQuery("SHOW TABLES LIKE '" + column + "';");
	bool empty = false;
	if(res->next())
		empty = true;
	delete res;
	return empty;
}


void Deta::insertColumn(std::string column, std::string field_name , std::string row) {
	stmt->execute("INSERT INTO " + column + " (" + field_name + ")" +" VALUES (" + row + ")");
}

void Deta::updateColumn(std::string column, std::string old_row,
		std::string new_row) {
	stmt->execute("UPDATE " + column + " SET " + new_row + " WHERE " + old_row);
}

sql::ResultSet* Deta::readColumn(std::string column, std::string row) {
	sql::ResultSet *res;
	res = stmt->executeQuery("SELECT * FROM " + column + " WHERE " + row);
	return res;
}

//delete sql::ResultSet after !!
sql::ResultSet* Deta::readAllColumn(std::string column) {
	sql::ResultSet *res;
	res = stmt->executeQuery("SELECT * FROM " + column);
	return res;
}

void Deta::deleteColumn(std::string column, std::string row) {
	stmt->execute("DELETE FROM " + column + " WHERE " + row);
}

