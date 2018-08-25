/*
 * Bash.cpp
 *
 *  Created on: Aug 20, 2018
 *      Author: Raishin
 */

#include "Bash.h"
#include "../Send/Send.h"

Bash::Bash()
	: ACommand("bash") {

}

Bash::~Bash() {
	std::cout << "Delete Bash class" << "\n";
}

std::string Bash::exec(const char* cmd) {
	FILE* pipe = popen(cmd, "r");
	if (!pipe)
		return "ERROR";
	char buffer[128];
	std::string result = "";
	while(!feof(pipe)) {
		if(fgets(buffer, 128, pipe) != NULL)
			result += buffer;
	}
	pclose(pipe);
	return result;
}

void Bash::run(std::string &my_string) {
	// remove "bash" from the string to execute shell command
	my_string = my_string.substr(5, my_string.size());

	std::string result = exec(my_string.c_str());
	Send send;
	if(result == "") {
		std::string command = "send \"done\" to 0762226688";
		send.run(command);
	} else {
		std::string command = "send \"" + result + "\" to 0762226688";
		send.run(command);
	}
}
