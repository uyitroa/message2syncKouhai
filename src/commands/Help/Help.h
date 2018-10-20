//
// Created by yuitora . on 06/10/2018.
//

#ifndef SRC_KOUHAI_COMMANDS_HELP_HELP_H
#define SRC_KOUHAI_COMMANDS_HELP_HELP_H


#include "../../abstracts/ACommand.h"
#include <vector>

class Help : public ACommand {
private:
	int search(std::string &prefix);
public:
	Help();
	~Help();

	virtual void run(std::string &my_string) override final;

};


#endif //MESSAGE2SYNC_HELP_H
