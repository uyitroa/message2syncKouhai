#ifndef SRC_KOUHAI_CORE_DORA_H_
#define SRC_KOUHAI_CORE_DORA_H_
#include <iostream>
#include <vector>
#include "../abstracts/ACommand.h"

class Dora {
private:
	std::vector<ACommand*> *command;

public:
	Dora(std::vector<ACommand*> &command);
	
	Dora();

	virtual ~Dora();
	void runCommand(std::string &my_string);
	
	// select the right input
	int findCommand(std::string &my_string);
};

#endif
