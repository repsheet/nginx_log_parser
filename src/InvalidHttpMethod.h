#pragma once

#include <utility>
#include "ProcessingRule.h"

class InvalidHttpMethod : public ProcessingRule {
public:
    explicit InvalidHttpMethod(Cache cache, std::set<std::string> valid_methods)
    : cache(cache)
    , valid_methods(std::move(valid_methods))
    , ProcessingRule()
    {}
    void process(Actors actors) override;
    void consume(LogEntry entry) override;
    void subscribe(moodycamel::ConcurrentQueue<LogEntry> queue) override;
private:
    std::string reason = "http.method.invalid";
    std::set<std::string> valid_methods;
    std::set <std::string> flagged_actors;
    Cache cache;
};
