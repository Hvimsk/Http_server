//
// Created by Mathias Costa Magnussen on 31/05/2025.
//

#include "../../Routes/Router.h"
#include "../Views/implementations/EchoView.h"
#include "../Views/implementations/UserAgentTestView.h"

class url_Binding {
    public:
    static Router CreateRouterWithBindings() {
        auto router = Router();
        router.addRoute("GET", "/echo/{str}", new EchoView());
        router.addRoute("GET", "/user-agent", new UserAgentTestView());
        return router;

    }
};
