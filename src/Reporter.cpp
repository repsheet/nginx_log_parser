#include <memory>
#include "Reporter.h"
#include "ProcessingRule.h"

void Reporter::write(const Cache& cache,
                     const Actors &actors,
                     const std::set<std::shared_ptr<ProcessingRule>>& rules) {
    for (const auto& rule : rules) {
        rule.get()->process(cache, actors);
    }
}
