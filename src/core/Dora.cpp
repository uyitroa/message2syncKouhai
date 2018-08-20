/*
 * Dora.cpp
 *
 *  Created on: Aug 20, 2018
 *      Author: Raishin
 */

#include "Dora.h"

Dora::Dora(std::vector<ICommand*> &command) {
	this->command = command;
}

void Dora::runCommand(std::string &my_string) {
	filterInput(my_string)->run(my_string);
}

ICommand* Dora::filterInput(std::string &my_string) {
	for(int count = 0; count < this->command.size(); count++) {
		std::string prefix = this->command[count]->getPrefix();
		std::string sub = my_string.substr(0, prefix.size());
		if(prefix == sub)
			return this->command[count];
	}
	return nullptr;
}
