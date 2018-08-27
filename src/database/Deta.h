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
#include <cppconn/resultset.h>
#include <cppconn/statement.h>

class Deta {
private:
	sql::Driver *driver;
	sql::Connection *con;
	sql::Statement *stmt;

	const std::string DATABASENAME = "mydatabase";
	const std::string NODATABASE = "Unknown database '" + this->DATABASENAME + "'";
	const std::string NOFIELDAMOUNT = " Table '" + this->DATABASENAME + ".amount' doesn't exist";

public:
	Deta(std::string address, std::string name, std::string password);
/*	Deta();*/
	virtual ~Deta();

	// CRUD CLASS
	void createClass(std::string name, std::string path);
	void readClass(std::vector<std::string> &names,
			std::vector<std::string> &paths);
	void updateClass(std::string table, std::string set, std::string where);
	void deleteClass(std::string table, std::string where);

	// save all class to header file classdata.h
	void updateHeader();

	void dropDatabase();

	// Create and delete table
	void createColumn(std::string column, std::string row);
	void deleteColumn(std::string column);
	bool columnExist(std::string column);

	// CRUD to table
	void insertColumn(std::string column, std::string field_name, std::string row);
	void updateColumn(std::string column, std::string old_row, std::string new_row);
	sql::ResultSet* readColumn(std::string column, std::string row); // first is always id
	sql::ResultSet* readAllColumn(std::string column);
	void deleteColumn(std::string column, std::string row);
};

#endif /* SRC_DATABASE_DETA_H_ */
