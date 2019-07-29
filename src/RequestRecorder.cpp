#include "RequestRecorder.h"

void RequestRecorder::process(Cache cache, Actors actors) {
    for (const auto & [address, actor] : actors) {
        if (address.empty()) {
            continue;
        }

        for (LogEntry request : actor.requests) {
            cache.record_request(address, request.toString());
        }

        for (auto const& request : actor.invalid_requests) {
            cache.record_request(address, request.request);
        }
    }
}
