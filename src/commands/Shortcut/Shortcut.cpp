/*
 * Shortcut.cpp
 *
 *  Created on: Aug 26, 2018
 *      Author: Raishin
 */

#include "Shortcut.h"
#include "../../database/classdata.h"
#include <fstream>


Shortcut::Shortcut()
	: ACommand("sc","To create:  sc alias:`real command`->`shortcut`\nTo delete:  sc delete() `shortcut`") {
	// TODO Auto-generated constructor stub

}

Shortcut::~Shortcut() {
	// TODO Auto-generated destructor stub
}

std::string Shortcut::runCommand(std::string &my_string) {
	int index = findCommand(my_string);


	if(index != -1) {
		try {
			return command_list.at(index)->run(my_string);
		} catch (std::exception &e) {
			std::string error = e.what();
			std::cout << error << "\n";
			return "Error: " + error;
		}
	}
	return "No such a command";
}

int Shortcut::findCommand(std::string &my_string) {
	for(int count = 0; count < command_list.size(); count++) {
		std::string prefix = command_list.at(count)->getPrefix(); // get prefix of each command
		std::string sub = my_string.substr(0, prefix.size()); // get prefix of the input

		// check if the prefix correspond to the command
		if(prefix == sub)
			return count;
	}
	return -1;
}

void Shortcut::create(std::string input, Deta &deta) {
	std::string real;
	std::string alias;
	for(int x = 0; x < input.size(); x++) {
		if(input.substr(x, 2) == "->") {
			real = input.substr(0, x);
			alias = input.substr(x + 2, input.size());
		}
	}

	try {
		deta.insert("shortcuts", "alias, real_command", "\"" + alias + "\", \"" + real +"\"");
	} catch (std::exception &e) {
		deta.update("shortcuts", "alias = \"" + alias + "\"", "real_command = \"" + real + "\"");
	}
}

std::string Shortcut::connectToManager(std::string &input, Deta &deta) {
	sqlite3_stmt *stmt = deta.read("shortcuts", "alias = \"" + input + "\"");
	if (sqlite3_step(stmt) != SQLITE_DONE) {
		std::string real = std::string((char *) sqlite3_column_text(stmt, 1));
		sqlite3_finalize(stmt);
		return runCommand(real);
	}
	sqlite3_finalize(stmt);
	return "No such shortcut";
}

void Shortcut::deleteSc(std::string alias, Deta &deta) {
	deta.remove("shortcuts" ,alias);
}

std::string helpShortcut(Deta &deta) {
	sqlite3_stmt *stmt = deta.readAll("shortcuts");
	std::string result;
	while (sqlite3_step(stmt) != SQLITE_DONE) {
		result += "\n";
		result += std::string((char*) sqlite3_column_text(stmt, 0));
		result += "  |   " + std::string((char*) sqlite3_column_text(stmt, 1));
	}
	return result;

}


std::string Shortcut::run(std::string& my_string) {
	removePrefix(my_string);

	Deta deta;
	if (my_string == "help") {
		std::string result = helpShortcut(deta);
		return result;
	}

	if(!deta.tableExist("shortcuts")) {
		std::cout << "Creating table" << "\n";
		deta.createTable("shortcuts", "alias VARCHAR(100) UNIQUE, real_command VARCHAR(100)");
	}

	if(my_string.substr(0, 6) == "alias:") {
		my_string = my_string.substr(6, my_string.size());

		this->create(my_string, deta);

		return "done";

	} else if(my_string.substr(0, 8) == "delete()"){
		my_string = "alias = '" + my_string.substr(9, my_string.size()) + "'";
		this->deleteSc(my_string, deta);
		return "done";

	} else {
		return this->connectToManager(my_string, deta);
	}
}
