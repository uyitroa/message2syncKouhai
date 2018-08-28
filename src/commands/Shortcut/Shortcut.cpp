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
		deta.insertColumn("shortcuts", "alias, real_command", "'" + alias + "', '" + real +"'");
	} catch (sql::SQLException &e) {
		deta.updateColumn("shortcuts", "alias = '" + alias + "'", "real_command = '" + real + "'");
	}
}

void Shortcut::connectToManager(std::string &input, Deta &deta) {
	sql::ResultSet *res = deta.readColumn("shortcuts", "alias = '" + input + "'");
	res->next();
	std::string real = res->getString(3);
	real = "0|" + real + "|\n";

	std::ofstream out;
	out.open("res/data/line.txt", std::ios::app);
	out << real;
	out.close();

	delete res;
}

void Shortcut::run(std::string& my_string) {
	my_string = my_string.substr(3, my_string.size()); // remove sc from the input
	Deta deta("localhost", "root", "Rairyuuaottg87");
	if(!deta.columnExist("shortcuts")) {
		std::cout << "Creating table" << "\n";
		deta.createColumn("shortcuts", "alias VARCHAR(100) UNIQUE, real_command VARCHAR(100)");
	}

	if(my_string.substr(0, 6) == "alias:") {
		my_string = my_string.substr(6, my_string.size());

		this->create(my_string, deta);

		Send send;
		std::string command = "send \"done\" to $0762226688";
		send.run(command);

	} else {
		this->connectToManager(my_string, deta);
	}
}
