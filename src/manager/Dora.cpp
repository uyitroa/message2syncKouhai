/*
 * Dora.cpp
 *
 *  Created on: Aug 20, 2018
 *      Author: Raishin
 */

#include "Dora.h"

Dora::Dora(std::vector<ACommand*> &command) {
	this->command = command;
}

void Dora::runCommand(std::string &my_string) {
	int index = findCommand(my_string);
	if(index != -1)
		this->command[index]->run(my_string);
}

int Dora::findCommand(std::string &my_string) {
	for(int count = 0; count < this->command.size(); count++) {
		std::string prefix = this->command[count]->getPrefix();
		std::string sub = my_string.substr(0, prefix.size());
		if(prefix == sub)
			return count;
	}
	return -1;
}
