/*
 * Deta.h
 *
 *  Created on: Aug 24, 2018
 *      Author: Raishin
 */

#ifndef SRC_DATABASE_DETA_H_
#define SRC_DATABASE_DETA_H_

#include <iostream>
#include <vector>
#include <mysql.h>

#include <mysql_connection.h>
#include <cppconn/driver.h>


class Deta {
private:
	sql::Driver *driver;
	sql::Connection *con;

	const std::string DATABASENAME = "mydatabase";
	const std::string NODATABASE = "Unknown database '" + this->DATABASENAME + "'";
	const std::string NOFIELDAMOUNT = " Table '" + this->DATABASENAME + ".amount' doesn't exist";

public:
	Deta(std::string address, std::string name, std::string password);
	Deta();
	~Deta();

	void createClass(std::string name, std::string path);

	void readClass(std::vector<std::string> &names,
			std::vector<std::string> &paths);
};

#endif /* SRC_DATABASE_DETA_H_ */
