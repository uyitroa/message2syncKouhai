/*
 * SharePic.h
 *
 *  Created on: Aug 26, 2018
 *      Author: Raishin
 */

#ifndef SRC_COMMANDS_SHAREPIC_SHAREPIC_H_
#define SRC_COMMANDS_SHAREPIC_SHAREPIC_H_

#include "../../abstracts/ACommand.h"
class SharePic : public ACommand {
public:
	SharePic();
	~SharePic();

	std::string exec(const char *cmd);
	virtual void run(std::string &my_string) override final;
};

#endif /* SRC_COMMANDS_SHAREPIC_SHAREPIC_H_ */
