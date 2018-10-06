//
// Created by yuitora . on 06/10/2018.
//

#ifndef SRC_SENPAI_SENDREQUEST_H
#define SRC_SENPAI_SENDREQUEST_H

#include <iostream>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

class SendRequest {
private:
	std::string host;
	std::string port;

public:
	SendRequest(std::string host = "127.0.0.1", std::string port = "8000");
	void sendpost(std::string json, std::string host_name = "127.0.0.1:8000", std::string path = "/receive/");
};


#endif //MESSAGE2SYNC_SENDREQUEST_H
