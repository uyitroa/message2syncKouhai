from django.views.decorators.csrf import csrf_exempt
from django.http import HttpResponse
from serverMessage2sync import data


def writeInput(inputdata):
	# add folder
	path_name = "res/data/line.txt"
	input_path = data.file_path + path_name
	myfile = open(input_path, "w")
	myfile.write(inputdata + "\n")


def getOutput():
	output = ""
	path_name = "res/output/line.txt"
	output_path = data.file_path + path_name
	file = open(output_path, "r")
	while output == data.before:
		output = file.read()
	data.before = output
	return output


@csrf_exempt
def receive(request, inputdata):
	try:
		writeInput(inputdata)
		return HttpResponse(getOutput())
	except Exception as e:
		print(e)
		return HttpResponse("Error: " + e)
