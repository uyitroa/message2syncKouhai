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
#include "../commands/Bash.h"

Koneku::Koneku() {
	// TODO Auto-generated constructor stub

}

Koneku::~Koneku() {
	// TODO Auto-generated destructor stub
}

std::string Koneku::readFile(std::string file_name) {
	std::string result = "";
	std::ifstream file;
	file.open(file_name);
	file.seekg(-1, file.end);
	char c = '\0';
	for(int x = -2; c != '\n'; x--) {
		file.seekg(x, file.end);
		result = c + result;
		c = file.get();
	}
	return result;
}

std::string Koneku::update() {
	system("app/baskup.sh");
	std::string my_string = readFile(this->FILE_NAME);
	return my_string;
}

bool Koneku::filterMsg(std::string& my_string) {
	if(my_string.substr(0, 2) == "1|") {
		my_string = my_string.substr(2, my_string.size() - 4);
		return true;
	} else {
		return false;
	}
}

void Koneku::launch() {
	std::string current_string = update();
	std::vector<ACommand*> command = {new Bash};
	Dora dora(command);

	while(true) {
		std::string new_string = update();
		if(!(new_string == current_string)) {
			current_string = new_string;
			std::cout << new_string << "\n";
			if(filterMsg(new_string))
				dora.runCommand(new_string);
		}
		sleep(WAIT);
	}
}
