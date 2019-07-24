#include "Callbacks.h"

InvalidEntryCallback Callbacks::add_invalid_request(Actors &actors) {
    return [&](auto entry) {
        auto actor = actors.find(entry.address);
        if (actor == actors.end()) {
            auto new_actor = Actor();
            new_actor.invalid_requests.emplace_back(entry);
            actors.emplace(std::make_pair(entry.address, new_actor));
        } else {
            actor->second.address = entry.address;
            actor->second.invalid_requests.emplace_back(entry);
        }
    };
}

LogEntryCallback Callbacks::add_request(Actors &actors) {
    return [&](auto entry) {
        auto actor = actors.find(entry.address);
        if (actor == actors.end()) {
            auto new_actor = Actor();
            new_actor.address = entry.address;
            new_actor.requests.emplace_back(entry);
            new_actor.user_agents.emplace(entry.user_agent);
            new_actor.response_code_to_count.insert(std::make_pair(entry.response_code, 1));
            new_actor.http_method_to_count.insert(std::make_pair(entry.method, 1));
            actors.emplace(std::make_pair(entry.address, new_actor));
        } else {
            actor->second.address = entry.address;
            actor->second.requests.emplace_back(entry);
            actor->second.user_agents.emplace(entry.user_agent);

            auto rc = actor->second.response_code_to_count.find(entry.response_code);
            if (rc != actor->second.response_code_to_count.end()) {
                rc->second++;
            } else {
                actor->second.response_code_to_count.insert(std::make_pair(entry.response_code, 1));
            }

            auto mc = actor->second.http_method_to_count.find(entry.method);
            if (mc != actor->second.http_method_to_count.end()) {
                mc->second++;
            } else {
                actor->second.http_method_to_count.insert(std::make_pair(entry.method, 1));
            }
        }
    };
}
