import os

before = ""
file_path = os.path.realpath(__file__)

# remove file name
file_name = "views.py"
file_path = file_path[0:len(file_path) - len(file_name)]

# remove folder name
folder_name = "src/server/serverMessage2sync/"
file_path = file_path[0:len(file_path) - len(folder_name)]