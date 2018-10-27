/*
 * Key.h
 *
 *  Created on: Aug 26, 2018
 *      Author: Raishin
 */

#ifndef SRC_KOUHAI_COMMANDS_KEY_KEY_H_
#define SRC_KOUHAI_COMMANDS_KEY_KEY_H_

#include "../../abstracts/ACommand.h"

class Key : public ACommand {
public:
	Key();
	~Key();

	std::string run(std::string &my_string) final;
};

#endif /* SRC_COMMANDS_KEY_KEY_H_ */
