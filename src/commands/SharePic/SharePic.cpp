/*
 * SharePic.cpp
 *
 *  Created on: Aug 26, 2018
 *      Author: Raishin
 */

#include "SharePic.h"

#include "../Send/Send.h"
SharePic::SharePic()
	: ACommand("sharepic") {
	// TODO Auto-generated constructor stub

}

SharePic::~SharePic() {
	// TODO Auto-generated destructor stub
}

std::string SharePic::exec(const char *cmd) {
	FILE* pipe = popen(cmd, "r");
	if (!pipe)
		return "ERROR";
	char buffer[256];
	std::string result = "";
	while(!feof(pipe)) {
		if(fgets(buffer, 256, pipe) != NULL) {
			result += buffer;
		}
	}
	pclose(pipe);
	return result;
}

void SharePic::run(std::string& my_string) {
	removePrefix(my_string);

	std::string command = "." + filepath + "/src/commands/SharePic/imgur.sh " + my_string;
	std::string result = exec(command.c_str());
	result = "send \"" + result +  "\" to $0762226688";
	Send send;
	send.run(result);
}
