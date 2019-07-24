#include <iostream>
#include "LoginBruteForce.h"

void LoginBruteForce::process(Cache cache, Actors actors) {
    for (auto const& actor : actors) {
        auto address = actor.second.address;
        auto count = 0;

        for (auto const& request : actor.second.requests) {
            if (request.uri == "/login" && request.response_code == 200) {
                ++count;
            }
        }

        if (count >= threshold) {
            if (address.empty()) {
                std::cout << "[" << reason << "]" " empty address, bypassing" << std::endl;
            } else {
                cache.blacklist(address, reason);
            }
        }
    }
}
