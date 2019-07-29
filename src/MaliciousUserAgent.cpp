#include <iostream>
#include <fstream>
#include "MaliciousUserAgent.h"

MaliciousUserAgent::MaliciousUserAgent(const std::string &dictionary_file) : ProcessingRule() {
    std::stringstream ss(dictionary_file);
    std::ifstream in(ss.str());
    std::string line;

    while (getline(in, line)) {
        dictionary.emplace(line);
    }
}

void MaliciousUserAgent::process(Cache cache, Actors actors) {
    for (auto & [address, actor] : actors) {
        if (address.empty()) {
            continue;
        }

        bool flagged = false;
        for (auto &user_agent : actor.user_agents) {
            if (flagged) {
                break;
            }

            if (dictionary.find(user_agent) != dictionary.end()) {
                flagged = true;
                cache.blacklist(address, reason);
            }
        }
    }
}
