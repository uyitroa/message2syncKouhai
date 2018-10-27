/*
 * Koneku.cpp
 *
 *  Created on: Aug 21, 2018
 *      Author: Raishin
 */

#include <fstream>
#include <unistd.h>
#include <vector>
#include <ctime>

#include "Koneku.h"
#include "../manager/Dora.h"
#include "../database/datapath.h"

Koneku::Koneku(std::string file_name, unsigned int wait) {
	this->file_name = std::move(file_name);
	this->wait = wait;

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
	std::ifstream file(file_name);
	std::string content( (std::istreambuf_iterator<char>(file) ),
	                     (std::istreambuf_iterator<char>()    ) );
	return content;
}

/*
 * read file and get the last message
 */
std::string Koneku::update() {
	std::string my_string = this->readFile(this->file_name);
	my_string = my_string.substr(0, my_string.size() - 1); // remove the \n of the message
	return my_string;
}

// check if it is the user messages or its own message
bool Koneku::filterMsg(std::string& my_string) {
	if(my_string.substr(0, 5) == "You: ") { // You: means controller message, else means its own message
		my_string = my_string.substr(5, my_string.size() - 5); // remove those symbol since we know that's the controller message
		return true;

	} else {
		return false;
	}
}

void Koneku::sendResult(std::string &result) {
	std::ofstream file;
	file.open(filepath + "res/output/line.txt");

	file << result;
	file.close();

}

// main method
void Koneku::launch() {
	std::string current_string = this->update();
	Dora dora; // dora is the manager of all commands. From the input, it will determine which command to run

	std::cout << "Setup finished" << "\n";

	while (current_string != this->EXIT_COMMAND) { // check if the order is not the exit
		std::string new_string = this->update();

		if (new_string != current_string) {
			std::cout << new_string << "\n";
			current_string = new_string;
			if (this->filterMsg(new_string)) {
				std::string result = dora.runCommand(new_string);
				sendResult(result);
			}
		}

		sleep(this->wait);
	}
}

void Koneku::del(std::vector<ACommand *> &command) {
	for (auto &element : command)
		delete element;
}

