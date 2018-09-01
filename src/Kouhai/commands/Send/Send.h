/*
 * Send.h
 *
 *  Created on: Aug 25, 2018
 *      Author: Raishin
 */

#ifndef SRC_COMMANDS_SEND_H_
#define SRC_COMMANDS_SEND_H_

#include <vector>

#include "../../abstracts/ACommand.h"
class Send : public ACommand {
private:
	std::vector<std::string> extract(std::string &my_string);

public:
	Send();
	virtual ~Send();

	virtual void run(std::string &my_string) override final;

};

#endif /* SRC_COMMANDS_SEND_H_ */
