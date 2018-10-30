/*
 * SharePic.cpp
 *
 *  Created on: Aug 26, 2018
 *      Author: Raishin
 */

#include "SharePic.h"
#include <fstream>

SharePic::SharePic()
	: ACommand("sharepic") {
	// TODO Auto-generated constructor stub

}

SharePic::~SharePic() {
	// TODO Auto-generated destructor stub
}

std::string SharePic::run(std::string& my_string) {
	removePrefix(my_string);

	std::string command = "mv " + my_string + " " + filepath + "res/images/toupload/sharepic.png";
	os.system(command.c_str());
	return result;
}
