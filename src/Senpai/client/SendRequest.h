//
// Created by yuitora . on 06/10/2018.
//

#ifndef SRC_SENPAI_SENDREQUEST_H
#define SRC_SENPAI_SENDREQUEST_H

#include <iostream>


class SendRequest {
private:
	static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);

public:
	SendRequest();
	void sendpost(std::string data, std::string url = "http://yuitorayuitora.localtunnel.me/");
};


#endif //MESSAGE2SYNC_SENDREQUEST_H
