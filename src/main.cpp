#include <iostream>
#include <fstream>


#include "core/Koneku.h"
#include "database/Deta.h"
#include "database/datapath.h"

void runserver() {
 	std::string command = "python3 " + filepath + "src/server/manage.py runserver &";
 	system(command.c_str());
 }

void controller(char choice) {
	if(choice == '1') {
		Koneku my_app;
		runserver();
		my_app.launch();
	} else {
		Deta deta;
		deta.updateHeader();
	}
}

int main(int argc, char *argv[]) {
	controller(argv[1][0]);
	return 0;
}
