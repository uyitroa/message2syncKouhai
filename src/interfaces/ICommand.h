/*
 * ICommand.h
 *
 *  Created on: Aug 20, 2018
 *      Author: Raishin
 */

#ifndef SRC_INTERFACES_ICOMMAND_H_
#define SRC_INTERFACES_ICOMMAND_H_

#include <iostream>

class ICommand {
protected:
	std::string prefix;

public:
	ICommand() {};
	virtual ~ICommand() = default;

	// "main method"
	virtual void run(std::string &my_string) = 0;

	virtual std::string& getPrefix() = 0;
};

#endif /* SRC_INTERFACES_ICOMMAND_H_ */
