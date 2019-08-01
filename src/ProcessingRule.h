#pragma once

#include "Cache.h"
#include "Actor.h"
#include "concurrentqueue.h"

class ProcessingRule {
public:
    virtual void process(Actors actors) = 0;
    virtual void consume(LogEntry entry) = 0;
    virtual void subscribe(moodycamel::ConcurrentQueue<LogEntry> queue) = 0;
};