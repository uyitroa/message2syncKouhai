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
#include "../database/datapath.h"

Koneku::Koneku(std::string file_name, int wait) {
	this->file_name = file_name;
	this->wait  = wait;

}

Koneku::Koneku() {
	 this->file_name = filepath + "res/data/line.txt";
	 this->wait = 3;
}
Koneku::~Koneku() {
	del(command_list);
}

// read the last message sent.
std::string Koneku::readFile(std::string file_name) {
	std::string result = "";
	std::ifstream file;

	file.open(file_name);
	file.seekg(-1, file.end); // go the last line
	char c = '\0';

	for(int x = -2; c != '\n'; x--) { // loop until \n which means the previous line. We only need the last line
		file.seekg(x, file.end);
		result = c + result;
		c = file.get();
	}
	return result;
}

/*
 * read file and get the last message
 */
std::string Koneku::update() {
	std::string file = filepath + "src/Kouhai/updater/baskup.sh";
	system(file.c_str()); // run the updater. Il will read the database and write new message to the file.
	std::string my_string = this->readFile(this->file_name);
	my_string = my_string.substr(0, my_string.size() - 1); // remove the \n of the message
	return my_string;
}

// check if it is the user messages or its own message
bool Koneku::filterMsg(std::string& my_string) {
	if(my_string.substr(0, 2) == "1|") { // 0| means controller message, and 1| means its own message
		my_string = my_string.substr(2, my_string.size() - 3); // remove those symbol since we know that's the controller message
		return true;

	} else {
		return false;
	}
}

// main method
void Koneku::launch() {
	std::string current_string = this->update();
	Dora dora; // dora is the manager of all commands. From the input, it will determine which command to run

	std::cout << "Setup finished" << "\n";

	while(current_string != this->EXIT_COMMAND) { // check if the order is not the exit
		std::string new_string = this->update();

		if(!(new_string == current_string)) {
			std::cout << new_string << "\n";
			current_string = new_string;
			if(this->filterMsg(new_string))
				dora.runCommand(new_string);
		}

		sleep(this->wait);
	}
}

void Koneku::del(std::vector<ACommand *> &command) {
	for (auto &element : command)
		delete element;
}

