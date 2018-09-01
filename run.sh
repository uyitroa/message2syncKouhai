g++ -std=c++11 -I/usr/local/mysql/include/ -L /usr/local/mysql-connector-c++-8.0/lib64/ -l mysqlcppconn -L /usr/local/mysql/lib/ -l mysqlclient -l sqlite3 src/main.cpp src/*/*/*.cpp -o ~/main.out
~/main.out
