//
// Created by Mathias Costa Magnussen on 29/05/2025.
//

#include "HttpRequest.h"

#include "HttpParser.h"



HttpRequest::HttpRequest(const std::string &method, const std::string &version, int client, const std::string &path) {
    this->method = method;
    this->version = version;
    this->client = client;
    this->path = path;

}

std::string HttpRequest::getMethod() const {
    return method;
}

int HttpRequest::getClient() const {
    return client;
}

std::string HttpRequest::getStatus() const {
    return status;
}

std::string HttpRequest::getPath() const {
    return path;
}

std::string HttpRequest::getVersion() const {
    return version;
}

const std::string HttpRequest::getRequestLine() const {
    //Todo validation is needed here for safety
    return version + " " + status + "" + "\r\n\r\n";

}

void HttpRequest::setStatus(std::string status) {
    this->status = status;
}

size_t HttpRequest::getLenght() {
    return requestLine.size();
}




