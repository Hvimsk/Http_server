//
// Created by Mathias Costa Magnussen on 31/05/2025.
//


#include "../interface/BaseView.h"


#include "EchoView.h"

void EchoView::process_incoming_request(Params& params) {
    if (params.contains("str")) {
        body = params.at("str");
        Status = "200 OK";
        content_type = "text/plain";
    } else {
        Status = "400 Bad Request";
    }

}
