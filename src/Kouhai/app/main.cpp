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
		Deta deta;
		deta.createClass("Bash", "../commands/Bash/Bash.h");
		deta.createClass("Send", "../commands/Send/Send.h");
		deta.createClass("Key", "../commands/Key/Key.h");
		deta.createClass("SharePic", "../commands/SharePic/SharePic.h");
		deta.createClass("Shortcut", "../commands/Shortcut/Shortcut.h");
		deta.updateHeader();
	}
	return 0;
}
