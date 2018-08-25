g++ -std=c++11 -I/usr/local/mysql/include/ -L/usr/local/mysql/lib/ src/*/*.cpp src/commands/*/*.cpp -lmysqlclient -lmysqlcppconn -o ~/main.out
~/main.out
