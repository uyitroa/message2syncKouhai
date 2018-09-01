git clone https://github.com/anhstudios/mysql-connector-cppi
mv mysql-connector-cppi/driver/* /usr/local/include/
mv -f mysql-connector-cppi/cppconn /usr/local/include/
rm -rf mysql-connector-cppi

echo PLEASE INSTALL MYSQL HERE:
echo https://dev.mysql.com/downloads/mysql/
echo https://dev.mysql.com/downloads/connector/cpp/8.0.html
echo THEN RUN sudo ./setup.sh
