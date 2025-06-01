//
// Created by Mathias Costa Magnussen on 29/05/2025.
//

#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H
#include <iostream>
#include <unistd.h>
#include <unordered_map>


class HttpRequest {


    public:
        HttpRequest(std::string method, int client, int status, std::string path);

        HttpRequest(const std::string & method, int client, const std::string & path);

        [[nodiscard]] std::string getMethod() const;
        [[nodiscard]] int getClient() const;
        [[nodiscard]] std::string getStatus() const;
        [[nodiscard]] std::string getPath() const;
        [[nodiscard]] std::string getVersion() const;


        [[nodiscard]] const std::string getRequestLine() const;


        void setStatus(std::string status);
        void setBody(std::string & body);
        void set_content_type(std::string & body);

        void setAcceptedReturnType(std::string acpt_type);
        std::string getHeader(const std::string& key) const;
        void setHeader(const std::string& key, const std::string& value);


        size_t getLenght() const;



    private:
        std::string method;
        std::unordered_map<std::string, std::string> headers;
        std::string version;
        int client;
        std::string status;
        std::string path;
        std::string requestLine;
        std::string body;
        std::string content_type;
        std::string content_length;
};




#endif //HTTPREQUEST_H
