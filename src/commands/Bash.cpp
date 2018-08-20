/*
 * Bash.cpp
 *
 *  Created on: Aug 20, 2018
 *      Author: Raishin
 */

#include "Bash.h"

Bash::Bash()
	: ACommand("bash") {

}

Bash::~Bash() {
	std::cout << "Delete Bash class" << "\n";
}

void Bash::run(std::string &my_string) {
	// remove bash from the string to execute bash command
	my_string = my_string.substr(5, my_string.size());

	system(my_string.c_str());
}
