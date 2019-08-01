#include "InvalidRequest.h"

void InvalidRequest::process(Actors actors) {
    for (const auto & [address, actor] : actors) {
        if (address.empty()) {
            continue;
        }

        if (!actor.invalid_requests.empty()) {
            cache.blacklist(address, reason);
        }
    }
}

void InvalidRequest::consume(LogEntry entry) {

}

void InvalidRequest::subscribe(moodycamel::ConcurrentQueue<LogEntry> queue) {

}
