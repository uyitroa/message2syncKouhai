/*
 * ACommand.h
 *
 *  Created on: Aug 20, 2018
 *      Author: Raishin
 */

#ifndef SRC_ABSTRACTS_ACOMMAND_H_
#define SRC_ABSTRACTS_ACOMMAND_H_

#include "../interfaces/ICommand.h"
#include <iostream>

class ACommand: public ICommand {
public:
	ACommand(std::string prefix);
	virtual ~ACommand();

	virtual std::string& getPrefix() override final;
};

#endif /* SRC_ABSTRACTS_ACOMMAND_H_ */
