#pragma once

#include "Cache.h"
#include "Actor.h"

class ProcessingRule {
public:
    virtual void process(Cache cache, Actors actors) = 0;
};