#include <utility>

//
// Created by yuitora . on 06/10/2018.
//

#include "SendRequest.h"
#include <istream>
#include <ostream>
#include <string>
#include <sstream>
//
SendRequest::SendRequest(std::string host, std::string port) {
	this->host = std::move(host);
	this->port = std::move(port);
}

void SendRequest::sendpost(std::string json, std::string host_name, std::string path) {
	boost::asio::io_service io_service;

	tcp::resolver resolver(io_service);
	tcp::resolver::query query(host, port);
	tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);

	tcp::socket socket_(io_service);
	boost::asio::connect(socket_, endpoint_iterator);

	boost::asio::streambuf request;
	std::ostream request_stream(&request);

	request_stream << "POST " << path << " HTTP/1.1 \r\n";
	request_stream << "Host: " << host_name << "\r\n";
	request_stream << "Content-Type: application/json; charset=utf-8\r\n";
	request_stream << "Accept: application/json\r\n";
	request_stream << "Content-Length: " << json.length() << "\r\n\r\n";
	request_stream << json << "\n\n";

	boost::asio::write(socket_, request);

}
