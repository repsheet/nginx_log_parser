#pragma once

#include "ProcessingRule.h"

class InvalidRequest : public ProcessingRule {
public:
    explicit InvalidRequest() : ProcessingRule() {}
    void process(Cache cache, Actors actors) override;
private:
    std::string reason = "http.request.invalid";
};
