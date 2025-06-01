//
// Created by Mathias Costa Magnussen on 01/06/2025.
//

#ifndef USERAGENTTESTVIEW_H
#define USERAGENTTESTVIEW_H
#include "../interface/BaseView.h"


class UserAgentTestView : public BaseView {
public:
    void process_incoming_request(Params& params) override;
};



#endif //USERAGENTTESTVIEW_H
