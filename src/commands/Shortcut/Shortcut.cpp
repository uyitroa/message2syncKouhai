/*
 * Shortcut.cpp
 *
 *  Created on: Aug 26, 2018
 *      Author: Raishin
 */

#include "Shortcut.h"


#include <fstream>

#include "../Send/Send.h"

Shortcut::Shortcut()
	: ACommand("sc") {
	// TODO Auto-generated constructor stub

}

Shortcut::~Shortcut() {
	// TODO Auto-generated destructor stub
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
		deta.insert("shortcuts", "alias, real_command", "'" + alias + "', '" + real +"'");
	} catch (std::exception &e) {
		deta.update("shortcuts", "alias = '" + alias + "'", "real_command = '" + real + "'");
	}
}

void Shortcut::connectToManager(std::string &input, Deta &deta) {
	sqlite3_stmt *stmt = deta.read("shortcuts", "alias = '" + input + "'");
	sqlite3_step(stmt);
	std::string real = std::string((char*) sqlite3_column_text(stmt, 0));
	real = "0|" + real + "|\n";

	std::ofstream out;
	out.open("res/data/line.txt", std::ios::app);
	out << real;
	out.close();

	sqlite3_finalize(stmt);
}

void Shortcut::deleteSc(std::string alias, Deta &deta) {
	deta.remove("shortcuts" ,alias);
}


void Shortcut::run(std::string& my_string) {
	my_string = my_string.substr(3, my_string.size()); // remove sc from the input
	Deta deta;
	if(!deta.tableExist("shortcuts")) {
		std::cout << "Creating table" << "\n";
		deta.createTable("shortcuts", "alias VARCHAR(100) UNIQUE, real_command VARCHAR(100)");
	}

	if(my_string.substr(0, 6) == "alias:") {
		my_string = my_string.substr(6, my_string.size());

		this->create(my_string, deta);

		Send send;
		std::string command = "send \"done\" to $0762226688";
		send.run(command);

	} else if(my_string.substr(0, 8) == "delete()"){
		my_string = "alias = '" + my_string.substr(9, my_string.size()) + "'";
		this->deleteSc(my_string, deta);

		Send send;
		std::string command = "send \"done\" to $0762226688";
		send.run(command);
	} else {
		this->connectToManager(my_string, deta);
	}
}
