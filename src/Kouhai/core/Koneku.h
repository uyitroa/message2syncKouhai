/*
 * Koneku.h
 *
 *  Created on: Aug 21, 2018
 *      Author: Raishin
 */

#ifndef SRC_APP_KONEKU_H_
#define SRC_APP_KONEKU_H_

#include <iostream>
#include "../abstracts/ACommand.h"

class Koneku {
private:
	const std::string EXIT_COMMAND = "1|exit()|";
	std::string file_name;
	int wait;

	std::string readFile(std::string file_name);
public:
	Koneku(std::string name, int time_wait);
	Koneku();

	~Koneku();

	std::string update();

	/*because the receive message is format : 1|message|
	so we need to remove the '1|' and the last '|'*/
	bool filterMsg(std::string &my_string);

	void launch();

	void del(std::vector<ACommand*> &command);

};

#endif /* SRC_APP_KONEKU_H_ */
