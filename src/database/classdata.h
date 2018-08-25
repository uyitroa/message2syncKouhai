#ifndef SRC_DATABASE_CLASSDATA_H_
#define SRC_DATABASE_CLASSDATA_H_
#include <iostream>
#include <vector>
#include "../abstracts/ACommand.h"
#include "../commands/Bash.h"
std::vector<ACommand*> command_list = {new Bash};
#endif