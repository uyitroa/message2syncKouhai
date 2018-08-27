/*
 * Shortcut.h
 *
 *  Created on: Aug 26, 2018
 *      Author: Raishin
 */

#ifndef SRC_COMMANDS_SHAREPIC_SHORTCUT_H_
#define SRC_COMMANDS_SHAREPIC_SHORTCUT_H_

#include "../../abstracts/ACommand.h"
#include "../../database/Deta.h"
class Shortcut: public ACommand {
private:
	void create(std::string input, Deta &deta);
	void connectToManager(std::string &input, Deta &deta);

public:
	Shortcut();
	virtual ~Shortcut();

	virtual void run(std::string &my_string) override final;
};

#endif /* SRC_COMMANDS_SHAREPIC_SHORTCUT_H_ */
