#include <iostream>
#include "InvalidHttpMethod.h"

void InvalidHttpMethod::process(Actors actors) {
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

void InvalidHttpMethod::subscribe(moodycamel::ConcurrentQueue<LogEntry> queue) {
    LogEntry entry;
    while(queue.try_dequeue(entry)) {
        consume(entry);
    }
}

void InvalidHttpMethod::consume(LogEntry entry) {
    auto address = entry.address;
    if (address.empty() || flagged_actors.find(address) == flagged_actors.end()) {
        return;
    }

    if (valid_methods.find(entry.method) == valid_methods.end()) {
        flagged_actors.emplace(address);
        cache.blacklist(address, reason + "[" + entry.method + "]");
    }
}
