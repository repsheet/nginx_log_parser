#pragma once

#include "ProcessingRule.h"

class InvalidRequest : public ProcessingRule {
public:
    explicit InvalidRequest(Cache cache)
    : cache(cache)
    , ProcessingRule()
    {}
    void process(Actors actors) override;
    void consume(LogEntry entry) override;
    void subscribe(moodycamel::ConcurrentQueue<LogEntry> queue) override;
private:
    std::string reason = "http.request.invalid";
    Cache cache;
};
