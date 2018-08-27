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
	: ACommand("key"){
	// TODO Auto-generated constructor stub

}

Key::~Key() {
	// TODO Auto-generated destructor stub
}

void Key::run(std::string& my_string) {
	my_string = my_string.substr(4, my_string.size()); //remove world key from input

	std::string cmd = "python src/commands/Key/key.py '" + my_string + "'";
	std::cout << cmd << "\n";
	system(cmd.c_str());
	Send send;
	std::string send_command = "send \"done\" to $0762226688";
	send.run(send_command);
}
