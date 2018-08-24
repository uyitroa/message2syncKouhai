/*
 * Deta.cpp
 *
 *  Created on: Aug 24, 2018
 *      Author: Raishin
 */

#include "Deta.h"

Deta::Deta(std::string address, std::string name, std::string password) {
	this->driver = get_driver_instance();
	this->con = driver->connect(address, name, password);
	this->con->setSchema("mydatabase");
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
