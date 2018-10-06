#include <iostream>
#include <fstream>

#include "Kouhai/core/Koneku.h"
#include "Kouhai/database/Deta.h"
#include "Kouhai/database/datapath.h"

void controller() {
	int choice;
	std::cout << "1.Run   2.Add class: ";
	std::cin >> choice;

	if(choice == 1) {
		Koneku my_app;
		my_app.launch();
	} else {
		Deta deta;
		deta.createClass("Bash", "../commands/Bash/Bash.h");
		deta.createClass("Send", "../commands/Send/Send.h");
		deta.createClass("Key", "../commands/Key/Key.h");
		deta.createClass("SharePic", "../commands/SharePic/SharePic.h");
		deta.createClass("Shortcut", "../commands/Shortcut/Shortcut.h");
		deta.updateHeader();
	}
}

void commander() {}

void runserver() {
	std::string command = "python3 " + filepath + "src/Kouhai/server/manage.py runserver &";
	system(command.c_str());
}

int main() {
	int type = 1;
	if(type == 1) {
		runserver();
		controller();
	} else if (type == 2) {
		commander();
	}
	return 0;
}
