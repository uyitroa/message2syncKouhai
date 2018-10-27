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
	char buffer[256];
	std::string result = "";
	while(!feof(pipe)) {
		if(fgets(buffer, 256, pipe) != NULL)
			result += buffer;
	}
	pclose(pipe);
	return result;
}

std::string Bash::run(std::string &my_string) {
	removePrefix(my_string);

	std::string result = exec(my_string.c_str());
	if(result == "")
		return "done";
	else
		return result;
}
