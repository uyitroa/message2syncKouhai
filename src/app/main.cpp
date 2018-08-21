#include <iostream>
#include <fstream>
#include <unistd.h>
#include <vector>

#include "../core/Dora.h"
#include "../commands/Bash.h"

const std::string FILE_NAME = "../res/data/line.txt";
const int WAIT = 3;
std::string readFile(std::string file_name) {
	std::string result = "";
	std::ifstream file;
	file.open(file_name);
	file.seekg(-1, file.end);
	char c = '\0';
	for(int x = -2; c != '\n'; x--) {
		file.seekg(x, file.end);
		result = c + result;
		c = file.get();
	}
	return result;
}

//check for new message
std::string update() {
	system("app/baskup.sh");
	std::string my_string = readFile(FILE_NAME);
	return my_string;
}

/*because the receive message is format : 1|message|
so we need to remove the '1|' and the last '|'*/
bool filterMsg(std::string &my_string) {
	if(my_string.substr(0, 2) == "1|") {
		my_string = my_string.substr(2, my_string.size() - 4);
		return true;
	} else {
		return false;
	}
}

int main() {
	std::string current_string = update();
	std::vector<ACommand*> command = {new Bash};
	Dora dora(command);

	while(true) {
		std::string new_string = update();
		if(!(new_string == current_string)) {
			current_string = new_string;
			std::cout << new_string << "\n";
			if(filterMsg(new_string))
				dora.runCommand(new_string);
		}
		sleep(WAIT);
	}
	return 0;
}
