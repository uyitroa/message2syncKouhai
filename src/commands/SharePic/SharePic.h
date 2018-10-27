/*
 * SharePic.h
 *
 *  Created on: Aug 26, 2018
 *      Author: Raishin
 */

#ifndef SRC_KOUHAI_COMMANDS_SHAREPIC_SHAREPIC_H_
#define SRC_KOUHAI_COMMANDS_SHAREPIC_SHAREPIC_H_

#include "../../abstracts/ACommand.h"
class SharePic : public ACommand {
public:
	SharePic();
	~SharePic() override;

	std::string exec(const char *cmd);

	std::string run(std::string &my_string) final;
};

#endif /* SRC_COMMANDS_SHAREPIC_SHAREPIC_H_ */
