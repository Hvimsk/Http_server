//
// Created by Mathias Costa Magnussen on 31/05/2025.
//

#ifndef BASEVIEW_H
#define BASEVIEW_H
#include <string>
#include <unordered_map>

#include "../../../http/HttpRequest.h"

class BaseView {
    public:
    virtual ~BaseView() = default;

    using Params = std::unordered_map<std::string, std::string>;

        std::string &getBody() {
            return body;
        };
        std::string &getStatus() {
            return Status;
        };

        std::string &getContent_type() {
            return content_type;
        };

        virtual void process_incoming_request(Params& params) = 0;

    protected:
        std::string Status;
        std::string body;
        std::string content_type;

};


#endif //BASEVIEW_H
