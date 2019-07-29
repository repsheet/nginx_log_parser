#include <iostream>
#include "InvalidHttpMethod.h"

void InvalidHttpMethod::process(Cache cache, Actors actors) {
    for (const auto & [address, actor] : actors) {
        if (address.empty()) {
            continue;
        }

        auto flagged = false;
        for (const auto &request : actor.requests) {
            if (valid_methods.find(request.method) == valid_methods.end()) {
                if (!flagged) {
                    flagged = true;
                    cache.blacklist(address, reason + "[" + request.method + "]");
                }
            }
        }
    }
}
