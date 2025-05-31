//
// Created by Mathias Costa Magnussen on 31/05/2025.
//

#include "../../Routes/Router.h"
#include "../Views/implementations/EchoView.h"

class url_Binding {
    public:
    static Router CreateRouterWithBindings() {
        auto router = Router();
        router.addRoute("GET", "/echo/{str}", new EchoView());
        return router;

    }
};
