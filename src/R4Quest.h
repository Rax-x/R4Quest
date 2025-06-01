#ifndef _R4QUEST_
#define _R4QUEST_

#include <string>
#include <vector>

#include <WiFi.h>

#define HTTP_OK             200
#define HTTP_NOT_FOUND      404
#define HTTP_TIMEOUT        408
#define HTTP_INTERNAL_ERROR 500
#define HTTP_UNAVAILABLE    503

class HTTPClient {
private:

    std::vector<std::string > headers;
    WiFiClient client;

    std::string &receive_response();
    void send_headers(const std::string url, const int port);
    std::string &send_request(const std::string url, const int port, const std::string method, const std::string body);

public:

    HTTPClient();
    ~HTTPClient();

    void clear_headers();

    void remove_header(const std::string header);
    void remove_header_by_key(const std::string key);

    std::string &request_delete(const std::string url, const int port = 80, const std::string body = "");
    std::string &request_get(const std::string url, const int port = 80, const std::string body = "");
    std::string &request_post(const std::string url, const int port = 80, const std::string body = "");
    std::string &request_put(const std::string url, const int port = 80, const std::string body = "");

    void set_authorization(const std::string auth);
    void set_header(const std::string header);
    void set_header(const std::string key, const std::string value);
};

#endif