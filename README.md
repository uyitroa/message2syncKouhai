# message2sync

A program which do everythin through imessage.
It lets you control your pc with phone

## Creating new command

Folder: src/commands/

To create a new command:
 - a class that inherit from ACommand in src/abstracts/ACommand.h
 - .h and .cpp
 - requires a virtual method run `virtual void run(std::string &input);` and contructors ACommand has a parameter which is the prefix string

Bash.h:
```cpp
#ifndef SRC_COMMANDS_BASH_H_
#define SRC_COMMANDS_BASH_H_

#include "../abstracts/ACommand.h"

// Bash is to run shell command
class Bash : public ACommand {
public:
	Bash();
	virtual ~Bash();

	virtual void run(std::string &my_string) override final; // the "main" method
};

#endif
```

Bash.cpp:
```cpp
#include "Bash.h"

Bash::Bash()
	: ACommand("bash") { // <- the prefix string here is "bash"

}

Bash::~Bash() {
}

void Bash::run(std::string &my_string) {
	// remove bash from the string to execute bash command
	my_string = my_string.substr(5, my_string.size());

	system(my_string.c_str()); // run shell script
}
```
