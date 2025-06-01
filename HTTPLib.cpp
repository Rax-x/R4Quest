#include "HTTPLib.h"

#include <string>
#include <vector>

HTTPClient::HTTPClient() {
    this->set_header("User-Agent: Arduino/2.2.0");
    this->set_header("Connection: close");
}

HTTPClient::~HTTPClient(){
    clean_headers();
}

void HTTPClient::clean_headers() {
    const int headers_length = this->headers.size();

    for (unsigned int i = 0; i < headers_length; i++)
        this->headers.pop_back();
}

void HTTPClient::remove_header(const std::string header) {
    for (unsigned int i = 0; i < this->headers.size(); i++)
        if (this->headers.at(i) == header)
            this->headers.erase(this->headers.begin() + i);
}

void HTTPClient::remove_header_by_key(const std::string key) {
    for (unsigned int i = 0; i < this->headers.size(); i++)
        if (split(this->headers.at(i), ":")[0] == key)
            this->headers.erase(this->headers.begin() + i);
}

int HTTPClient::send_request(const std::string url, const std::string method, const std::string body) {
    
}

void HTTPClient::set_authorization(const std::string auth) {
    this->set_header("Authorization", auth);
}

void HTTPClient::set_header(const std::string header) {
    for (unsigned int i = 0; i < this->headers.size(); i++)
        if (split(this->headers.at(i), ":")[0] == split(header, ":")[0]) {
            this->headers.at(i) = header;
            return;
        }

    this->headers.insert(this->headers.end(), header);
}

void HTTPClient::set_header(const std::string key, const std::string value) {
    for (unsigned int i = 0; i < this->headers.size(); i++)
        if (split(this->headers.at(i), ":")[0] == key) {
            this->headers.at(i) = key + ": " + value;
            return;
        }

    this->headers.insert(this->headers.end(), key + ": " + value);
}

static std::vector<std::string> split(std::string s, std::string delimiter) {
    unsigned int delim_len {delimiter.length()};
    unsigned int pos_start {0}, pos_end {0};

    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find(delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back(token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}