//
// Created by Mathias Costa Magnussen on 29/05/2025.
//

#include "HttpParser.h"
#include "../Routes/Router.h"
static inline void failure(std::string_view message)
{
    std::cout << "Malformed request, " << message << std::endl;
    return throw std::runtime_error("Malformed request");
}



HttpRequest HttpParser::parseRequest(int client,Router* router) {
    std::string buffer = HttpParser::GetContentOfRequestFromClient(client);
    std::string_view request(buffer);

    const auto methodEndPosition = request.find(' ');
    if (methodEndPosition == std::string::npos) {
        failure("cant find method");
    }

    std::string method;
    method = request.substr(0, methodEndPosition);
    request.remove_prefix(methodEndPosition + 1);

    std::string version;
    version = "HTTP/1.1";



    std::string path;
    const auto PathEndPosition = request.find(' ');
    if (PathEndPosition == std::string::npos) {
        failure("cant find path");
    }
    path = request.substr(0, PathEndPosition);

    //todo send the fucker to the router,
    // current issue. i need to handle data transfers
    // no idea just yet, but who cares hihi

    // this returns HTTP Request type
    return router->CreateHttpResponse(method,path,client);


}

std::string HttpParser::GetContentOfRequestFromClient(int client) {
    constexpr int buffer_size = 1024;
    char buffer[buffer_size];
    std::string request;

    int bytes_read = 0;
    while ((bytes_read = read(client, buffer, buffer_size)) > 0) {
        request.append(buffer, bytes_read);

        // If less than buffer_size, likely end of request (but not guaranteed).
        if (bytes_read < buffer_size) {
            break;
        }
    }

    if (request.empty()) {
        return "malformed request";
    }

    return request;
}

