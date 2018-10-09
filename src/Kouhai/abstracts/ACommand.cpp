/*
 * ACommand.cpp
 *
 *  Created on: Aug 20, 2018
 *      Author: Raishin
 */

#include "ACommand.h"
ACommand::ACommand(std::string prefix) {
	this->prefix = prefix;
	this->information = prefix + " to run";
}

ACommand::ACommand(std::string prefix, std::string information) {
	this->prefix = prefix;
	this->information = information;
}

ACommand::~ACommand() {
	std::cout << "Delete ACommand abstract class" << "\n";
}


std::string& ACommand::getPrefix() {
	return this->prefix;
}

std::string& ACommand::help() {
	return this->information;
}

void ACommand::removePrefix(std::string &input) {
	input = input.substr(prefix.size() + 1, input.size());
}

