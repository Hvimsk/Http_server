//
// Created by Mathias Costa Magnussen on 29/05/2025.
//

#include "HttpRequest.h"

#include "HttpParser.h"



HttpRequest::HttpRequest(const std::string &method, int client, const std::string &path) {
    this->method = method;
    this->version = "HTTP/1.1";
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
    std::string StringBuilder;

    // Status line
    if (version.data() && status.data()) {
        StringBuilder += version + " " + status + "\r\n";  // e.g. HTTP/1.1 200 OK
    } else {
        StringBuilder += "HTTP/1.1 500 Internal Server Error\r\n";
    }

    // Headers
    if (content_type.data()) {
        StringBuilder += content_type + "\r\n";
    }

    if (content_length.data()) {
        StringBuilder += content_length + "\r\n";
    }

    // End of headers
    StringBuilder += "\r\n";

    // Body
    if (body.data()) {
        StringBuilder += body;
    }

    return StringBuilder;
}


void HttpRequest::setStatus(std::string status) {
    this->status = status;
}

void HttpRequest::setBody(std::string &body) {
    this->body = body;
    content_length = "Content-Length: " + std::to_string(this->body.size());
}

void HttpRequest::set_content_type(std::string &response_content_type) {

    content_type = "Content-Type: "+ response_content_type;

}

size_t HttpRequest::getLenght() {
    return requestLine.size();
}




