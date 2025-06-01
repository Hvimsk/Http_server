//
// Created by Mathias Costa Magnussen on 01/06/2025.
//

#include "../interface/BaseView.h"
#include "UserAgentTestView.h"
void UserAgentTestView::process_incoming_request(Params& params) {
    if (params.contains("User-Agent")) {
        body = params.at("User-Agent");
        Status = "200 OK";
        content_type = "text/plain";
    } else {
        Status = "400 Bad Request";
    }

}