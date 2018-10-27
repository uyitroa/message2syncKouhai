from django.views.decorators.csrf import csrf_exempt
from django.http import HttpResponse
from serverMessage2sync import data
import time
import os


def writeInput(inputdata):
	path_name = "res/data/line.txt"
	input_path = data.file_path + path_name
	myfile = open(input_path, "w")
	myfile.write(inputdata + "\n")


def getOutput():
	path_name = "res/output/line.txt"
	output_path = data.file_path + path_name
	myfile = open(output_path, "r")
	data.output = myfile.read()

	while data.output == "":
		time.sleep(2)
		data.output = myfile.read()

	myfile.close()

	myfile = open(output_path, "w")
	myfile.write("")
	myfile.close()

	return data.output


def runProgram(inputdata):
	file_name = "main.out"
	command = data.file_path + file_name + ' 3 "' + inputdata + '"'
	print(command)
	os.system(command)


@csrf_exempt
def receive(request, inputdata):
	"""

	:type inputdata: string
	"""
	try:
		writeInput(inputdata)
		runProgram(inputdata)
		return HttpResponse(getOutput())
	except Exception as e:
		print(e)
		return HttpResponse("Error: " + str(e))
