/*
 * ACommand.cpp
 *
 *  Created on: Aug 20, 2018
 *      Author: Raishin
 */

#include "ACommand.h"
ACommand::ACommand(std::string prefix) {
	this->prefix = prefix;
}

ACommand::~ACommand() {
	std::cout << "Delete ACommand abstract class" << "\n";
}


std::string& ACommand::getPrefix() {
	return this->prefix;
}
