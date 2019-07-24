#pragma once

#include "ProcessingRule.h"

class RequestRecorder : public ProcessingRule {
public:
    explicit RequestRecorder() : ProcessingRule() {}
    void process(Cache cache, Actors actors) override;
};
