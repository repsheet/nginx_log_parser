#pragma once

#include "ProcessingRule.h"

class LoginBruteForce : public ProcessingRule {
public:
    explicit LoginBruteForce(long threshold) : threshold(threshold), ProcessingRule() {}
    void process(Cache cache, Actors actors) override;
private:
    long threshold;
    std::string reason = "http.login.brute_force";
};
