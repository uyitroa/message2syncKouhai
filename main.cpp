#include <iostream>
#include <fstream>
#include <unistd.h>
const std::string FILE_NAME = "backup/+33762226688/iMessage\\;-\\;+33762226688.txt";
constexpr int WAIT = 5;
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

std::string update() {
	system("./baskup.sh");
	std::string command_copy = "cp " + FILE_NAME + " idk.txt";
	system(&command_copy[0u]);
	std::string my_string = readFile("idk.txt");
	return my_string;
}

void execute(std::string command) {

}

int main() {
	std::string current_string = "";
	while(true) {
		std::string new_string = update();
		if(!(new_string == current_string)) {
			execute(new_string);
			current_string = new_string;
		}
		sleep(WAIT);
	}
	return 0;
}
