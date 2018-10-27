#include <iostream>
#include <fstream>

#include "manager/Dora.h"
#include "core/Koneku.h"
#include "database/Deta.h"
#include "database/datapath.h"

void runserver() {
	std::string command = "python3 " + filepath + "src/server/manage.py runserver &";
	system(command.c_str());
 }

void controller(char *choice[]) {
	std::cout << choice[1][0] << "\n";
	if(choice[1][0] == '1') {
		Koneku my_app;
		runserver();
		my_app.launch();
	} else  if (choice[1][0] == '2') {
		Deta deta;
		deta.updateHeader();
	} else if (choice[1][0] == '3') {
		Koneku somefonction;
		std::string command = choice[2];
		if (somefonction.filterMsg(command)) {
			Dora dora;
			command = dora.runCommand(command);
			somefonction.sendResult(command);
		}

	}
}

int main(int argc, char *argv[]) {
	controller(argv);
	return 0;
}
