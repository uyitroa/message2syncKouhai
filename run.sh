./setup.sh
g++ -std=c++11 src/commands/*/*.cpp src/main.cpp src/*/*.cpp -o main.out -lsqlite3 -lcurl
python3 src/server/manage.py runserver 0.0.0.0:8686
