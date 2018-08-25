#include <iostream>

#include "../core/Koneku.h"
#include "../database/Deta.h"

int main() {
	int choice;
	std::cout << "1.Run   2.Add class: ";
	std::cin >> choice;

	if(choice == 1) {
		Koneku my_app;
		my_app.launch();
	} else {
		Deta deta("localhost", "root", "Rairyuuaottg87");
/*		std::string name = "Bash";
		std::string path = "../commands/Bash/Bash.h";*/
		deta.createClass("Bash", "../commands/Bash/Bash.h");
		deta.createClass("Send", "../commands/Send/Send.h");
		/*std::cout << "OK" << "\n";*/
		deta.updateHeader();
	}
	return 0;
}
