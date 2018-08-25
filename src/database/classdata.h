#ifndef SRC_DATABASE_CLASSDATA_H_
#define SRC_DATABASE_CLASSDATA_H_

#include <iostream>
#include <vector>

#include "../abstracts/ACommand.h"
#include "../commands/Bash/Bash.h"
#include "../commands/Send/Send.h"

std::vector<ACommand*> command_list = {new Bash, new Send};

#endif