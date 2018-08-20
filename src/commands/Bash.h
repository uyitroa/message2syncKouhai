/*
 * Bash.h
 *
 *  Created on: Aug 20, 2018
 *      Author: Raishin
 */

#ifndef SRC_COMMANDS_BASH_H_
#define SRC_COMMANDS_BASH_H_

#include "../abstracts/ACommand.h"

class Bash : public ACommand {
public:
	Bash();
	virtual ~Bash();

	virtual void run(std::string &my_string) override final;
};

#endif /* SRC_COMMANDS_BASH_H_ */
