//
// Created by Mathias Costa Magnussen on 29/05/2025.
//

#include "RouteValidator.h"

RouteValidator::RouteValidator() {
    // Initialize the set of allowed paths
    allowedPaths = {
        "/",
    };
}

RouteValidator::~RouteValidator() = default;

bool RouteValidator::isAllowed(const std::string& path) const {
    return allowedPaths.find(path) != allowedPaths.end();
}