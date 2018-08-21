#ifndef SRC_CORE_DORA_H_
#define SRC_CORE_DORA_H_
#include <iostream>
#include <vector>
#include "../abstracts/ACommand.h"

class Dora {
private:
	std::vector<ACommand*> command;

public:
	Dora(std::vector<ACommand*> &command);
	
	void runCommand(std::string &my_string);
	
	// select the right input
	ACommand* filterInput(std::string &my_string);
};

#endif
