#include <iostream>
#include <fstream>
#include <unistd.h>
const std::string FILE_NAME = "../res/data/line.txt";
const int WAIT = 5;
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
	system("./baskup.sh");
	std::string my_string = readFile(FILE_NAME);
	return my_string;
}

/*void execute(std::string command) {

}*/

int main() {
	std::string current_string = update();
	while(true) {
		std::string new_string = update();
		if(!(new_string == current_string)) {
			std::cout << new_string << "\n";
			//execute(new_string);
			current_string = new_string;
		}
		sleep(WAIT);
	}
	return 0;
}
