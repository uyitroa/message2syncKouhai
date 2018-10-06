/*
 * ACommand.h
 *
 *  Created on: Aug 20, 2018
 *      Author: Raishin
 */

#ifndef SRC_ABSTRACTS_ACOMMAND_H_
#define SRC_ABSTRACTS_ACOMMAND_H_

#include <iostream>
#include "../database/datapath.h"

class ACommand {
protected:
	std::string prefix;
	std::string information;


public:
	ACommand(std::string prefix);
	ACommand(std::string prefix, std::string information);
	virtual ~ACommand();

	/*
	 * "main" method
	 * It will be called when the controller need the command
	 * The whole input will be passed by reference parameter
	 */
	virtual void run(std::string &my_string) = 0;

	virtual std::string& getPrefix();

	/*
	 * This method will be called when the controller send "help"
	 */
	virtual std::string& help();
};

#endif /* SRC_ABSTRACTS_ACOMMAND_H_ */
