//
// Created by yuitora . on 06/10/2018.
//

#include "Help.h"
#include "../../database/classdata.h"

Help::Help() : ACommand("helpmepls") {
}

Help::~Help() = default;

int Help::search(std::string &prefix) {
	for (int index = 0; index < command_list.size(); index++) {
		if (command_list[index]->getPrefix() == prefix)
			return index;
	}
	return -1;
}

std::string Help::run(std::string &my_string) {
	std::string output;
	if (my_string == prefix) {
		for (auto &element : command_list) {
			output += element->help() + "\n";
		}
	} else {
		removePrefix(my_string);
		int index = search(output);
		if (index != -1)
			output = command_list[index]->help() + "\n";
		else
			output = "no such command \n";
	}
	return output;
}
