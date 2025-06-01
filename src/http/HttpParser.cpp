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
    std::istringstream stream(buffer);
    std::string line;

    std::string method, path, version;
    std::unordered_map<std::string, std::string> headers;

    // Parse request line
    std::getline(stream, line);
    std::istringstream reqLine(line);
    reqLine >> method >> path >> version;

    // Parse headers
    while (std::getline(stream, line)) {
        if (line == "\r" || line == "" || line == "\n") break;

        // Remove \r
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }

        size_t colon = line.find(':');
        if (colon != std::string::npos) {
            std::string key = line.substr(0, colon);
            std::string value = line.substr(colon + 1);
            if (!value.empty() && value[0] == ' ') value.erase(0, 1);
            headers[key] = value;
        }
    }

    // Build HttpRequest object
    HttpRequest req(method, client, path);
    for (const auto& [k, v] : headers) {
        req.setHeader(k,v);
    }

    return router->CreateHttpResponse(req);

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

