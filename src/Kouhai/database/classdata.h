#ifndef SRC_DATABASE_CLASSDATA_H_
#define SRC_DATABASE_CLASSDATA_H_

#include <iostream>
#include <vector>

#include "../abstracts/ACommand.h"
#include "../commands/Bash/Bash.h"
#include "../commands/Send/Send.h"
#include "../commands/Key/Key.h"
#include "../commands/SharePic/SharePic.h"
#include "../commands/Shortcut/Shortcut.h"

static std::vector<ACommand*> command_list = {new Bash, new Send, new Key, new SharePic, new Shortcut};

#endif