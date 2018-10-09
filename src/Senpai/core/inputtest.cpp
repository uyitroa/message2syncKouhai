//
// Created by yuitora . on 09/10/2018.
//

#include "../client/SendRequest.h"
#include <iostream>
void input() {
	SendRequest sendRequest;

	std::string inputstring;

	std::cout << "Send: ";
	std::getline(std::cin, inputstring);
	inputstring = "1|" + inputstring;
	sendRequest.sendpost(inputstring);

}