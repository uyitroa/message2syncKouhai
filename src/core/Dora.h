#ifndef SRC_CORE_DORA_H_
#define SRC_CORE_DORA_H_
#include <iostream>
#include <vector>
#include "../interfaces/ICommand.h"

class Dora {
private:
	std::vector<ICommand*> command;

public:
	Dora(std::vector<ICommand*> &command);
	
	void runCommand(std::string &my_string);
	
	// select the right input
	ICommand* filterInput(std::string &my_string);
};

#endif
