/*
 * Key.cpp
 *
 *  Created on: Aug 26, 2018
 *      Author: Raishin
 */

#include "Key.h"
#include <fstream>

Key::Key()
	: ACommand("key") {
	help_string = "['\\t', '\\n', '\\r', ' ', '!', '#', '$', '%', '&', '(',\n"
	              "')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3', '4', '5', '6', '7',\n"
	              "'8', '9', ':', ';', '<', '=', '>', '?', '@', '[', '\\\\', ']', '^', '_', '`',\n"
	              "'a', 'b', 'c', 'd', 'e','f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',\n"
	              "'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~',\n"
	              "'accept', 'add', 'alt', 'altleft', 'altright', 'apps', 'backspace',\n"
	              "'browserback', 'browserfavorites', 'browserforward', 'browserhome',\n"
	              "'browserrefresh', 'browsersearch', 'browserstop', 'capslock', 'clear',\n"
	              "'convert', 'ctrl', 'ctrlleft', 'ctrlright', 'decimal', 'del', 'delete',\n"
	              "'divide', 'down', 'end', 'enter', 'esc', 'escape', 'execute', 'f1', 'f10',\n"
	              "'f11', 'f12', 'f13', 'f14', 'f15', 'f16', 'f17', 'f18', 'f19', 'f2', 'f20',\n"
	              "'f21', 'f22', 'f23', 'f24', 'f3', 'f4', 'f5', 'f6', 'f7', 'f8', 'f9',\n"
	              "'final', 'fn', 'hanguel', 'hangul', 'hanja', 'help', 'home', 'insert', 'junja',\n"
	              "'kana', 'kanji', 'launchapp1', 'launchapp2', 'launchmail',\n"
	              "'launchmediaselect', 'left', 'modechange', 'multiply', 'nexttrack',\n"
	              "'nonconvert', 'num0', 'num1', 'num2', 'num3', 'num4', 'num5', 'num6',\n"
	              "'num7', 'num8', 'num9', 'numlock', 'pagedown', 'pageup', 'pause', 'pgdn',\n"
	              "'pgup', 'playpause', 'prevtrack', 'print', 'printscreen', 'prntscrn',\n"
	              "'prtsc', 'prtscr', 'return', 'right', 'scrolllock', 'select', 'separator',\n"
	              "'shift', 'shiftleft', 'shiftright', 'sleep', 'space', 'stop', 'subtract', 'tab',\n"
	              "'up', 'volumedown', 'volumemute', 'volumeup', 'win', 'winleft', 'winright', 'yen',\n"
	              "'command', 'option', 'optionleft', 'optionright']";
}

Key::~Key() {}

std::string Key::run(std::string& my_string) {
	removePrefix(my_string);

	if (my_string == "help") {
		return help_string;
	}

	std::string cmd = "python " + filepath + "src/commands/Key/key.py \"" + my_string + "\"";
	std::cout << cmd << "\n";
	system(cmd.c_str());
	return "done";
}
