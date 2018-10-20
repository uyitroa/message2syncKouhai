//
// Created by yuitora . on 06/10/2018.
//

#include "SendRequest.h"
#include <../../libs/curl/curl.h>
//
SendRequest::SendRequest() = default;

size_t SendRequest::WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}
void SendRequest::sendpost(std::string data, std::string url) {
	CURL *curl;
	CURLcode res;
	std::string readBuffer;

	std::string full_url = url + data + "/";
	curl = curl_easy_init();
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, full_url.c_str());
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);

		std::cout << readBuffer << std::endl;
	}


}
