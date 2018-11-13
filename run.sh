g++ -std=c++11 src/commands/*/*.cpp src/main.cpp src/*/*.cpp -o ~/main.out -lsqlite3
~/main.out "$*"
