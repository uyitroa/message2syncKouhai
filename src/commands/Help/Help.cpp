//
// Created by yuitora . on 06/10/2018.
//

#include "Help.h"
#include "../Send/Send.h"
#include "../../database/classdata.h"

Help::Help() : ACommand("helpmepls") {
}

Help::~Help() {

}

int Help::search(std::string &prefix) {
	for (int index = 0; index < command_list.size(); index++) {
		if (command_list[index]->getPrefix() == prefix)
			return index;
	}
	return -1;
}

void Help::run(std::string &my_string) {
	removePrefix(my_string);
	std::string output;
	if (my_string.empty()) {
		for (auto &element : command_list) {
			output += element->help() + "\n";
		}
	} else {
		int index = search(output);
		if (index != -1)
			output = command_list[index]->help() + "\n";
		else
			output = "no such command \n";
	}
	std::cout << output << "\n";
	output = "send \"" + output + "\" to $0762226688";
	Send send;
	send.run(output);
}