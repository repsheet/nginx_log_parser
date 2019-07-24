#pragma once

#include <vector>
#include <set>
#include <unordered_map>
#include "LogEntry.h"
#include "InvalidEntry.h"

struct Actor
{
    std::string address;
    std::vector<LogEntry> requests;
    std::vector<InvalidEntry> invalid_requests;
    std::set<std::string> user_agents;
    std::unordered_map<int, long long> response_code_to_count;
    std::unordered_map<std::string, long long> http_method_to_count;
};

using Actors = std::unordered_map<std::string, Actor>;