#include "InvalidRequest.h"

void InvalidRequest::process(Cache cache, Actors actors) {
    for (const auto & [address, actor] : actors) {
        if (address.empty()) {
            continue;
        }

        if (!actor.invalid_requests.empty()) {
            cache.blacklist(address, reason);
        }
    }
}
