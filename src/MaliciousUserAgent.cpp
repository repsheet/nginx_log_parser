#include <iostream>
#include <fstream>
#include "MaliciousUserAgent.h"

MaliciousUserAgent::MaliciousUserAgent(const std::string &dictionary_file) : ProcessingRule() {
    std::stringstream ss(dictionary_file);
    std::ifstream in(ss.str());
    std::string line;

    while (getline(in, line)) {
        std::cout << line << std::endl;
        dictionary.emplace(line);
    }
}

void MaliciousUserAgent::process(Cache cache, Actors actors) {
    for (auto &actor : actors) {
        auto address = actor.second.address;
        bool flagged = false;
        for (auto &user_agent : actor.second.user_agents) {
            if (flagged) {
                break;
            }

            if (dictionary.find(user_agent) != dictionary.end()) {
                flagged = true;
                if (address.empty()) {
                    std::cout << "[" << reason << "]" " empty address, bypassing" << std::endl;
                } else {
                    cache.blacklist(address, reason);
                }
            }
        }
    }
}
