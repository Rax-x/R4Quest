#include "R4Quest.h"

HTTPClient::HTTPClient() {
    this->set_header("User-Agent: ArduinoWiFi/1.1");
    this->set_header("Connection: close");
}

HTTPClient::~HTTPClient(){
    this->clear_headers();
}

void HTTPClient::clear_headers() {
    this->headers.clear();
}

std::string &HTTPClient::receive_response() {
    std::string response {};

    while (client.available()) {
        char c = client.read();
        response.append(c);
    }

    return response;
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

std::string &HTTPClient::request_delete(const std::string url, const int port, const std::string body) {
    this->send_request(url, port, "DELETE", body);
}

std::string &HTTPClient::request_get(const std::string url, const int port, const std::string body) {
    this->send_request(url, port, "GET", body);
}

std::string &HTTPClient::request_post(const std::string url, const int port, const std::string body) {
    this->send_request(url, port, "POST", body);
}

std::string &HTTPClient::request_put(const std::string url, const int port, const std::string body) {
    this->send_request(url, port, "PUT", body);
}

void HTTPClient::send_headers(const std::string url, const int port) {
    if (this->client.available())
        for (auto &header: headers) 
            this->client.println(header);
}

std::string &HTTPClient::send_request(const std::string url, const int port, const std::string method, const std::string body) {
    std::string response {};

    if (this->client.connect(url, port)) {
        this->client.print(method);
        this->client.println(" / HTTP/1.1");
        this->client.print("Host: ");
        this->client.println(url);
        
        this->send_headers();

        this->client.println(body);
        this->client.println();

        response = this->receive_response();
        this->client.stop();
    }

    return response
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