g++ -std=c++11 src/Kouhai/commands/*/*.cpp src/main.cpp src/*/*/*.cpp -o ~/main.out -lsqlite3 -lcurl
~/main.out "$*"
