//
// Created by Mathias Costa Magnussen on 29/05/2025.
//

#ifndef HTTPPARSER_H
#define HTTPPARSER_H
#include "HttpRequest.h"


class HttpParser {
    public:
    static HttpRequest parseRequest(int client);

    static std::string GetContentOfRequestFromClient(int client);
};



#endif //HTTPPARSER_H
