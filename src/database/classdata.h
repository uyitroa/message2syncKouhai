/*
 * classdata.h
 *
 *  Created on: Aug 23, 2018
 *      Author: Raishin
 */

#ifndef SRC_DATABASE_CLASSDATA_H_
#define SRC_DATABASE_CLASSDATA_H_
#include <iostream>
#include <vector>

#include "../abstracts/ACommand.h"
#include "../commands/Bash.h"

std::vector<ACommand*> command_list = {new Bash};

#endif /* SRC_DATABASE_CLASSDATA_H_ */
