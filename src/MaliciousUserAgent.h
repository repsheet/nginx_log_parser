#pragma once

#include "ProcessingRule.h"

class MaliciousUserAgent : public ProcessingRule {
public:
    explicit MaliciousUserAgent(const std::string& dictionary_file);
    void process(Cache cache, Actors actors) override;
private:
    std::string reason = "http.user_agent.malicious";
    std::set<std::string> dictionary;
};

