#pragma once

#include "ProcessingRule.h"

class MaliciousUserAgent : public ProcessingRule {
public:
    explicit MaliciousUserAgent(Cache cache, const std::string& dictionary_file);
    void process(Actors actors) override;
    void consume(LogEntry entry) override;
    void subscribe(moodycamel::ConcurrentQueue<LogEntry> queue) override;
private:
    std::string reason = "http.user_agent.malicious";
    std::set<std::string> dictionary;
    Cache cache;
};

