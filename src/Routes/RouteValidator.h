//
// Created by Mathias Costa Magnussen on 29/05/2025.
//

#ifndef ROUTEVALIDATOR_H
#define ROUTEVALIDATOR_H
#include <string>
#include <unordered_set>

class RouteValidator {
public:
    RouteValidator(); // constructor
    ~RouteValidator(); // destructor

    bool isAllowed(const std::string& path) const;

private:
    std::unordered_set<std::string> allowedPaths;
};




#endif //ROUTEVALIDATOR_H
