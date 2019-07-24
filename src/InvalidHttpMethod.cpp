#include <iostream>
#include "InvalidHttpMethod.h"

void InvalidHttpMethod::process(Cache cache, Actors actors) {
    for (auto const& actor : actors) {
        auto address = actor.second.address;
        auto flagged = false;
        for (auto const& request : actor.second.requests) {
            if (valid_methods.find(request.method) == valid_methods.end()) {
                if (!flagged) {
                    flagged = true;
                    if (address.empty()) {
                        std::cout << "[" << reason << "]" " empty address, bypassing" << std::endl;
                    } else {
                        cache.blacklist(address, reason + "[" + request.method + "]");
                    }
                }
            }
        }
    }
}
