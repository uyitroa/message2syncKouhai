import os
import sys
if sys.platform == "darwin":
	sys.path.append("/usr/local/lib/python2.7/site-packages/")
try:
	import pyautogui
except:
	os.system("pip install pyautogui")
	os.system("pip install pyobjc")
	os.system("pip install pyobjc-core")
	import pyautogui

def main():
	cmd = sys.argv[1]
	cmd = cmd.split(";")
	for x in cmd:
		string = "pyautogui." + x
		exec(string)

if __name__ == "__main__":
	main()
