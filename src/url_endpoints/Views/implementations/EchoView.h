// EchoView.h
#ifndef ECHOVIEW_H
#define ECHOVIEW_H

#include "../interface/BaseView.h"

class EchoView : public BaseView {
public:
    void process_incoming_request(Params& params) override;
};

#endif // ECHOVIEW_H
