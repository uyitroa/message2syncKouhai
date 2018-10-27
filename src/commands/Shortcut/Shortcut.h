/*
 * Shortcut.h
 *
 *  Created on: Aug 26, 2018
 *      Author: Raishin
 */

#ifndef SRC_KOUHAI_COMMANDS_SHORTCUT_SHORTCUT_H_
#define SRC_KOUHAI_COMMANDS_SHORTCUT_SHORTCUT_H_

#include "../../abstracts/ACommand.h"
#include "../../database/Deta.h"
class Shortcut: public ACommand {
private:
	void create(std::string input, Deta &deta);
	void connectToManager(std::string &input, Deta &deta);
	void deleteSc(std::string alias, Deta &deta);

public:
	Shortcut();

	~Shortcut() override;

	std::string run(std::string &my_string) final;
};

#endif /* SRC_COMMANDS_SHAREPIC_SHORTCUT_H_ */
