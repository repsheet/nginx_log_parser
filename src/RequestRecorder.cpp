#include "RequestRecorder.h"

void RequestRecorder::process(Cache cache, Actors actors) {
    for (auto const& actor : actors) {
        auto address = actor.second.address;

        for (LogEntry request : actor.second.requests) {
            cache.record_request(address, request.toString());
        }

        for (auto const& request : actor.second.invalid_requests) {
            cache.record_request(address, request.request);
        }
    }
}
