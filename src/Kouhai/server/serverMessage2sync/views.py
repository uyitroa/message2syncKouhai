from django.views.decorators.csrf import csrf_exempt
from django.http import JsonResponse
import json
import os


@csrf_exempt
def receive(request):
	try:
		file_path = os.path.realpath(__file__)

		# remove file name
		file_name = "views.py"
		file_path = file_path[0:len(file_path) - len(file_name)]

		# remove folder name
		folder_name = "src/Kouhai/server/serverMessage2sync/"
		file_path = file_path[0:len(file_path) - len(folder_name)]

		# add folder
		path_name = "res/line.txt"
		file_path += path_name

		myfile = open(file_path, "a")
		data = json.loads(request.body)
		myfile.write(data + "\n")

		return JsonResponse({'update': True})

	except Exception as e:
		return JsonResponse({'update': False})
