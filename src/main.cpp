#include <iostream>
#include <fstream>


#include "Kouhai/core/Koneku.h"
#include "Kouhai/database/Deta.h"
#include "Kouhai/database/datapath.h"

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
