#include <iostream>

#include "../core/Koneku.h"

int main() {
	int choice;
	std::cout << "1.Run   2.Add class: ";
	std::cin >> choice;

	if(choice == 1) {
		Koneku my_app;
		my_app.launch();
	}
	return 0;
}
