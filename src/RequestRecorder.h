#pragma once

#include "ProcessingRule.h"

class RequestRecorder : public ProcessingRule {
public:
    explicit RequestRecorder(Cache cache)
    : cache(cache)
    , ProcessingRule()
    {}
    void process(Actors actors) override;
    void consume(LogEntry entry) override;
    void subscribe(moodycamel::ConcurrentQueue<LogEntry> queue) override;
private:
    Cache cache;
};
