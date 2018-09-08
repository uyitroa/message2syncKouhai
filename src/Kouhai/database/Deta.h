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
#include <sqlite3.h>

class Deta {
private:

	sqlite3 *db;
	std::string path;
	std::string databasename;

	void exec(const char *cmd);
	int sizeClass();

public:
	Deta(std::string path = "res/data/", std::string databasename = "mydatabase.db"); // default values
/*	Deta();*/
	virtual ~Deta();

	// CRUD CLASS
	void createClass(std::string name, std::string path);
	void readClass(std::vector<std::string> &names,
			std::vector<std::string> &paths);
	void updateClass(std::string set, std::string where);
	void deleteClass(std::string where);

	/*
	 * save all command class to header file classdata.h
	 * store all command in an vector using object slicing technique
	 */
	void updateHeader();

	void dropDatabase();

	// Create and delete table
	void createTable(std::string column, std::string row);
	void deleteTable(std::string column);
	bool tableExist(std::string column);

	/*
	 * Allow user to manage data that they want to store
	 */
	void insert(std::string column, std::string field_name, std::string values);
	sqlite3_stmt* read(std::string column, std::string values);
	sqlite3_stmt* readAll(std::string column);
	void update(std::string column, std::string old_row, std::string new_row);
	void remove(std::string column, std::string row);
};

#endif /* SRC_DATABASE_DETA_H_ */
