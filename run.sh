g++ -std=c++11 -I/usr/local/mysql/include/ -L /usr/local/mysql-connector-c++-8.0/lib64/ -l mysqlcppconn -L /usr/local/mysql/lib/ -l mysqlclient src/*/*.cpp src/commands/*/*.cpp -o ~/main.out
~/main.out
