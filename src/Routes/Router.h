//
// Created by Mathias Costa Magnussen on 31/05/2025.
//

#ifndef ROUTER_H
#define ROUTER_H



#include <string>
#include <unordered_map>
#include <vector>
#include <functional>
#include <iostream>

#include <sstream>

#include "../http/HttpRequest.h"
#include "../url_endpoints/Views/interface/BaseView.h"

struct RouteKey {
    std::string method;
    std::string path;

    bool operator==(const RouteKey& other) const {
        return method == other.method && path == other.path;
    }
};

// Required for using RouteKey in unordered_map
namespace std {
    template<>
    struct hash<RouteKey> {
        std::size_t operator()(const RouteKey& k) const {
            return hash<std::string>()(k.method) ^ (hash<std::string>()(k.path) << 1);
        }
    };
}
class Router {
public:
    using Params = std::unordered_map<std::string, std::string>;
  //  using Handler = std::function<void(const Params&)>;

    void addRoute(const std::string& method, const std::string& pattern, BaseView* response_view) {
        routePatterns.push_back({method, pattern});
        routeHandlers[{method, pattern}] = response_view;
    }

    HttpRequest CreateHttpResponse(const std::string& method, const std::string& path,int client) const {
        for (const auto& [routeMethod, pattern] : routePatterns) {
            if (routeMethod != method) continue;

            auto params = extractParams(pattern, path);
            if (!params.empty()) {
                auto it = routeHandlers.find({method, pattern});
                if (it != routeHandlers.end()) {
                    it->second->process_incoming_request(params);
                    HttpRequest response = HttpRequest(method, client, path);
                    response.setBody(it->second->getBody());
                    response.setStatus(it->second->getStatus());
                    response.set_content_type(it->second->getContent_type());
                    return response;
                }
            }
        }
        std::cout << "404 Not Found: " << method << " " << path << std::endl;
        //Todo Add malformed response
        HttpRequest resposne = HttpRequest(method, client, path);
        resposne.setStatus("404 Not Found: ");
        return resposne;
    }



private:
    std::vector<RouteKey> routePatterns;
    std::unordered_map<RouteKey, BaseView*> routeHandlers;

    static Params extractParams(const std::string& pattern, const std::string& path) {
        Params params;
        std::istringstream patternStream(pattern);
        std::istringstream pathStream(path);
        std::string patternToken, pathToken;

        while (std::getline(patternStream, patternToken, '/') && std::getline(pathStream, pathToken, '/')) {
            if (!patternToken.empty() && patternToken.front() == '{' && patternToken.back() == '}') {
                std::string paramName = patternToken.substr(1, patternToken.length() - 2);
                params[paramName] = pathToken;
            } else if (patternToken != pathToken) {
                return {};
            }
        }

        if (!patternStream.eof() || !pathStream.eof()) {
            return {};
        }

        return params;
    }
};


#endif //ROUTER_H
