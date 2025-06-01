#ifndef _HTTPLIB_
#define _HTTPLIB_

#include <string>
#include <vector>

class HTTPClient {
private:

    std::vector<std::string > headers;

public:

    HTTPClient();
    ~HTTPClient();

    void clean_headers();

    int request_get(const std::string url);
    int request_delete(const std::string url, const std::string body);
    int request_post(const std::string url, const std::string body);
    int request_put(const std::string url, const std::string body);

    int send_request(const std::string url, const std::string method, const std::string body);

    void remove_header(const std::string header);
    void remove_header_by_key(const std::string key);

    void set_authorization(const std::string auth);
    void set_header(const std::string header);
    void set_header(const std::string key, const std::string value);
};


#endif