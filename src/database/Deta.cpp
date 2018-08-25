/*
 * Deta.cpp
 *
 *  Created on: Aug 24, 2018
 *      Author: Raishin
 */

#include "Deta.h"

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
			stmt->execute("CREATE DATABSE " + this->DATABASENAME);
			this->con->setSchema(this->DATABASENAME);
			stmt->execute("CREATE TABLE classes (id INT NOT NULL AUTO_INCREMENT, name VARCHAR(40), path VARCHAR(200), created DATE, PRIMARY KEY(id))");

			// check if column amount exist for readClass, which need a vector, and if we know already the amount, no need for push_back();
			stmt->execute("CREATE TABLE classes_amount (id INT NOT NULL AUTO_INCREMENT, amount INT, PRIMARY KEY(id))");
			stmt->execute("INSERT INTO classes_amount (amount) VALUES (0)");
			delete stmt;
		}
	}

}

Deta::Deta() { // @suppress("Class members should be properly initialized")
	Deta("tcp://127.0.0.1:3306", "root", "encrypted");
}

Deta::~Deta() {
	delete this->con;
}

void Deta::createClass(std::string name, std::string path) {
	sql::PreparedStatement *prep_stmt;

	prep_stmt = this->con->prepareStatement("INSERT INTO classes(name, path, created) VALUES(?, ?, NOW())");

	prep_stmt->setString(1, name);
	prep_stmt->setString(2, path);

	prep_stmt->execute();

	delete prep_stmt;
}

void Deta::readClass(std::vector<std::string>& names,
		std::vector<std::string>& paths) {
	sql::Statement *stmt = this->con->createStatement();
	sql::ResultSet *res;

	res = stmt->executeQuery("SELECT * from classes_amount");
	int size = res->getInt(2);

	names.reserve(size);
	paths.reserve(size);

	res = stmt->executeQuery("SELECT * from classes");
	int index = 0;
	while(res->next()) {
		names[index] = res->getString(2);
		paths[index] = res->getString(3);
		index++;
	}

	delete res;
	delete stmt;

}
