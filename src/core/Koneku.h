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
	const std::string FILE_NAME = "../res/data/line.txt";
	const int WAIT = 3;

	std::string readFile(std::string file_name);
public:
	Koneku();
	~Koneku();

	std::string update();

	/*because the receive message is format : 1|message|
	so we need to remove the '1|' and the last '|'*/
	bool filterMsg(std::string &my_string);

	void launch();
};

#endif /* SRC_APP_KONEKU_H_ */
