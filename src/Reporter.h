#pragma once

#include "Callbacks.h"
#include "ProcessingRule.h"

class Reporter {
public:
    static void write(const Cache& cache, const Actors &actors, const std::set<std::shared_ptr<ProcessingRule>>& set);
};
