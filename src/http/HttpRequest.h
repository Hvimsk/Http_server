//
// Created by Mathias Costa Magnussen on 29/05/2025.
//

#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H
#include <iostream>
#include <unistd.h>


class HttpRequest {


    public:
    HttpRequest(std::string method, std::string version, int client, int status, std::string path);

    HttpRequest(const std::string & method, const std::string & version, int client, const std::string & path);

    [[nodiscard]] std::string getMethod() const;
        [[nodiscard]] int getClient() const;
        [[nodiscard]] std::string getStatus() const;
        [[nodiscard]] std::string getPath() const;
        [[nodiscard]] std::string getVersion() const;
        [[nodiscard]] const std::string getRequestLine() const;


        void setStatus(std::string status);

    size_t getLenght();



private:
        std::string method;
        std::string version;
        int client;
        std::string status;
        std::string path;
        std::string requestLine;
};




#endif //HTTPREQUEST_H
