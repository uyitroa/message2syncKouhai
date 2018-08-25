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
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

Deta::Deta(std::string address, std::string name, std::string password) {
	this->driver = get_driver_instance();
	this->con = driver->connect(address, name, password);

	try {
		this->con->setSchema(this->DATABASENAME);

	} catch (sql::SQLException &e) {
		// if the database is not created
		if(e.what() == this->NODATABASE) {
			sql::Statement *stmt = this->con->createStatement();
			stmt->execute("CREATE DATABASE " + this->DATABASENAME);
			this->con->setSchema(this->DATABASENAME);
			stmt->execute("CREATE TABLE classes (id INT NOT NULL AUTO_INCREMENT, name VARCHAR(40), path VARCHAR(200), created DATE, PRIMARY KEY(id))");

			// check if column amount exist for readClass, which need a vector, and if we know already the amount, no need for push_back();
			stmt->execute("CREATE TABLE classes_amount (id INT NOT NULL AUTO_INCREMENT, amount INT, PRIMARY KEY(id))");
			stmt->execute("INSERT INTO classes_amount (amount) VALUES (0)");
			delete stmt;
		}
	}

}

Deta::~Deta() {
/*	this->dropDatabase();
	delete this->con;*/
}

void Deta::createClass(std::string name, std::string path) {
	sql::Statement *stmt;
	stmt = this->con->createStatement();

	stmt->execute("INSERT INTO classes (name, path, created) VALUES ('" + name + "', '" + path + "', NOW())");
	this->updateClass("classes_amount", "amount = amount + 1", "id = 1");

	delete stmt;
}

void Deta::readClass(std::vector<std::string>& names,
	std::vector<std::string>& paths) {
	sql::Statement *stmt = this->con->createStatement();
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
	delete stmt;
}

void Deta::updateClass(std::string table, std::string set, std::string where) {
	sql::Statement *stmt;
	stmt = this->con->createStatement();

	stmt->execute("UPDATE " + table + " SET " + set + " WHERE " + where);

	delete stmt;
}

void Deta::deleteClass(std::string table, std::string where) {
	sql::Statement *stmt;
	stmt = this->con->createStatement();

	stmt->execute("DELETE FROM " + table + " WHERE " + where);

	delete stmt;
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
	sql::Statement *stmt;
	stmt = this->con->createStatement();
	stmt->execute("drop database " + this->DATABASENAME);
}
