/*
 * Koneku.cpp
 *
 *  Created on: Aug 21, 2018
 *      Author: Raishin
 */

#include <fstream>
#include <unistd.h>
#include <vector>

#include "Koneku.h"
#include "../manager/Dora.h"

Koneku::Koneku(std::string file_name, int wait) {
	this->file_name = file_name;
	this->wait  = wait;

}

Koneku::Koneku() {
	 this->file_name = "res/data/line.txt";
	 this->wait = 3;
}
Koneku::~Koneku() {
	// TODO Auto-generated destructor stub
}

// read the last message sent.
std::string Koneku::readFile(std::string file_name) {
	std::string result = "";
	std::ifstream file;

	file.open(file_name);
	file.seekg(-1, file.end); // go the last line
	char c = '\0';

	for(int x = -2; c != '\n'; x--) { // loop until \n
		file.seekg(x, file.end);
		result = c + result;
		c = file.get();
	}
	return result;
}

std::string Koneku::update() {
	system("src/app/baskup.sh");
	std::string my_string = this->readFile(this->file_name);
	my_string = my_string.substr(0, my_string.size() - 1);
	return my_string;
}

// check if it is the user messages or its own message
bool Koneku::filterMsg(std::string& my_string) {
	if(my_string.substr(0, 2) == "1|" || my_string.substr(0, 2) == "0|") { // 1| means user messages, and 0| means its own message
		my_string = my_string.substr(2, my_string.size() - 3);
		return true;

	} else {
		return false;
	}
}

// main method
void Koneku::launch() {
	std::string current_string = this->update();
	Dora dora;

	std::cout << "Setup finished" << "\n";

	while(current_string != this->EXIT_COMMAND) {
		std::string new_string = this->update();
		if(!(new_string == current_string)) {
			current_string = new_string;
			std::cout << new_string << "\n";
			if(this->filterMsg(new_string))
				dora.runCommand(new_string);
		}
		sleep(this->wait);
	}
}

