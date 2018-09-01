/*
 * Send.cpp
 *
 *  Created on: Aug 25, 2018
 *      Author: Raishin
 */

#include "Send.h"

#include <fstream>
Send::Send()
	: ACommand("send") {
	// TODO Auto-generated constructor stub

}

Send::~Send() {
	// TODO Auto-generated destructor stub
}

/*
 * return type @vector
 * vector[0] = text
 * vector[1] = number
 */
std::vector<std::string> Send::extract(std::string& my_string) {
	std::vector<std::string> string(2);
	for(int x = 0; x < my_string.size(); x++) {
		if(my_string.substr(x, 6) == "\" to $") {
			string[0] = my_string.substr(0, x + 1);
			string[1] = my_string.substr(x + 6, my_string.size());
			break;
		}

		if(my_string[x] == '"' && x != 0){
			my_string[x] = '\'';
		}
	}
	return string;
}

/*
 * Input: send "hello world" to 123456789
 */
void Send::run(std::string& my_string) {
	// remove send from the command
	my_string = my_string.substr(5, my_string.size());

	std::vector<std::string> string_list = this->extract(my_string);
	std::string command = "osascript src/commands/Send/send.scpt " + string_list[1] + " " + string_list[0] + " &";
	system(command.c_str());
}


