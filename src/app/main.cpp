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
		std::string name = "Bash";
		std::string path = "../commands/Bash.h";
		deta.createClass(name, path);
		/*std::cout << "OK" << "\n";*/
		deta.updateHeader();
	}
	return 0;
}
