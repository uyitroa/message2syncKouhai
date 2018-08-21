/*
 * ACommand.h
 *
 *  Created on: Aug 20, 2018
 *      Author: Raishin
 */

#ifndef SRC_ABSTRACTS_ACOMMAND_H_
#define SRC_ABSTRACTS_ACOMMAND_H_

#include <iostream>

class ACommand {
protected:
	std::string prefix;

public:
	ACommand(std::string prefix);
	virtual ~ACommand();

	virtual void run(std::string &my_string) = 0;

	virtual std::string& getPrefix();
};

#endif /* SRC_ABSTRACTS_ACOMMAND_H_ */
