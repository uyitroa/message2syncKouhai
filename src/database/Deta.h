/*
 * Deta.h
 *
 *  Created on: Aug 24, 2018
 *      Author: Raishin
 */

#ifndef SRC_DATABASE_DETA_H_
#define SRC_DATABASE_DETA_H_

#include <iostream>
#include <mysql.h>

#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

class Deta {
private:
	sql::Driver *driver;
	sql::Connection *con;

public:
	Deta(std::string address, std::string name, std::string password);
	Deta();
	~Deta();

	void createClass(std::string name, std::string path);


};

#endif /* SRC_DATABASE_DETA_H_ */
