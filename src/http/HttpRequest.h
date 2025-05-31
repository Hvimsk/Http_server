//
// Created by Mathias Costa Magnussen on 29/05/2025.
//

#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H
#include <iostream>
#include <unistd.h>


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

        size_t getLenght();

        void setUserAgent(std::string user_agent);

        void setAcceptedReturnType(std::string acpt_type);

    private:
        std::string method;
        std::string User_agent;
        std::string accepted_returnType;
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
