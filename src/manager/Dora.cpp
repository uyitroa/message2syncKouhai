/*
 * Dora.cpp
 *
 *  Created on: Aug 20, 2018
 *      Author: Raishin
 */

#include "Dora.h"

#include <exception>

#include "../database/classdata.h"

Dora::Dora(std::vector<ACommand*> &command) {
	this->command = &command;
}

Dora::Dora() {
	this->command = &command_list;
}

Dora::~Dora() {
	std::cout << "Delete dora" << "\n";
	for(int x = 0; x < command->size(); x++)
		delete command->at(x);
}


void Dora::runCommand(std::string &my_string) {
	int index = findCommand(my_string);


	if(index != -1) {
		try {
			this->command->at(index)->run(my_string);
		} catch (std::exception &e) {
			std::string error = e.what();
			std::cout << error << "\n";
		}
	}
}

int Dora::findCommand(std::string &my_string) {
	for(int count = 0; count < this->command->size(); count++) {
		std::string prefix = this->command->at(count)->getPrefix(); // get prefix of each command
		std::string sub = my_string.substr(0, prefix.size()); // get prefix of the input

		// check if the prefix correspond to the command
		if(prefix == sub)
			return count;
	}
	return -1;
}
