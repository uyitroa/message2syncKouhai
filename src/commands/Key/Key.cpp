/*
 * Key.cpp
 *
 *  Created on: Aug 26, 2018
 *      Author: Raishin
 */

#include "Key.h"
#include "../Send/Send.h"
#include <fstream>

Key::Key()
	: ACommand("key") {}

Key::~Key() {}

void Key::run(std::string& my_string) {
	removePrefix(my_string);

	std::string cmd = "python " + filepath + "src/commands/Key/key.py '" + my_string + "'";
	std::cout << cmd << "\n";
	system(cmd.c_str());
	Send send;
	std::string send_command = "send \"done\" to $0762226688";
	send.run(send_command);
}
