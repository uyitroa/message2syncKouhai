/*
 * Koneku.h
 *
 *  Created on: Aug 21, 2018
 *      Author: Raishin
 */

#ifndef SRC_KOUHAI_CORE_KONEKU_H_
#define SRC_KOUHAI_CORE_KONEKU_H_

#include <iostream>
#include "../database/classdata.h"

class Koneku {
private:
	const std::string EXIT_COMMAND = "1|exit()|";
	std::string file_name;
	unsigned int  wait;

	/*
	 * readFile, the file store the conversation of the controller and the computer
	 */
	std::string readFile(std::string file_name);
public:
	Koneku(std::string name, unsigned int time_wait);
	Koneku();

	~Koneku();
	/*
	 * read file and get the last message
	 */
	std::string update();

	/*
	 * because the receive message is format : 1|message|
	 * so we need to remove the '1|' and the last '|'
	 * 1| reprensent computer, and 0| represent the controller
	 */
	bool filterMsg(std::string &my_string);

	void launch();

	/*
	 * object slicing use dynamic memory, so we need to prevent memory leak
	 */
	void del(std::vector<ACommand*> &command);

};

#endif /* SRC_APP_KONEKU_H_ */
