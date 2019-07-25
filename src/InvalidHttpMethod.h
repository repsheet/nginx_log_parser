#pragma once

#include <utility>
#include "ProcessingRule.h"

class InvalidHttpMethod : public ProcessingRule {
public:
    explicit InvalidHttpMethod(std::set<std::string> valid_methods)
    : valid_methods(std::move(valid_methods))
    , ProcessingRule()
    {}
    void process(Cache cache, Actors actors) override;
private:
    std::string reason = "http.method.invalid";
    std::set<std::string> valid_methods;
};
