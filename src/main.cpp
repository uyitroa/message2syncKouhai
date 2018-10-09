#include <iostream>
#include <fstream>


#include "Kouhai/core/Koneku.h"
#include "Kouhai/database/Deta.h"
#include "Kouhai/database/datapath.h"
void input();

void runserver() {
	std::string command = "python3 " + filepath + "src/Kouhai/server/manage.py runserver 0.0.0.0:8000 &";
	system(command.c_str());
}
void controller() {
	int choice;
	std::cout << "1.Run   2.Add class: ";
	std::cin >> choice;

	if(choice == 1) {
		Koneku my_app;
		runserver();
		my_app.launch();
	} else {
		Deta deta;
		deta.updateHeader();
	}
}

void commander() {
	input();
}



int main(int argc, char *argv[]) {
	if(argv[1][0] == '1') {
		controller();
	} else if (argv[1][0] == '2') {
		commander();
	}
	return 0;
}
