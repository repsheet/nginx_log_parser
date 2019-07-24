#include <iostream>
#include "InvalidRequest.h"

void InvalidRequest::process(Cache cache, Actors actors) {
    for (auto const& actor : actors) {
        auto address = actor.second.address;
        if (!actor.second.invalid_requests.empty()) {
            if (address.empty()) {
                std::cout << "[" << reason << "]" " empty address, bypassing" << std::endl;
            } else {
                cache.blacklist(address, reason);
            }
        }
    }
}
