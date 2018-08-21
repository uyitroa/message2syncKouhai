/*
 * Koneku.h
 *
 *  Created on: Aug 21, 2018
 *      Author: Raishin
 */

#ifndef SRC_APP_KONEKU_H_
#define SRC_APP_KONEKU_H_

#include <iostream>
class Koneku {
private:
	std::string file_name;
	int wait;

	std::string readFile(std::string file_name);
public:
	Koneku(std::string file_name  = "../res/data/line.txt", int wait = 3);
	~Koneku();

	std::string update();

	/*because the receive message is format : 1|message|
	so we need to remove the '1|' and the last '|'*/
	bool filterMsg(std::string &my_string);

	void launch();
};

#endif /* SRC_APP_KONEKU_H_ */
