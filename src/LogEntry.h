#pragma once

#include <string>
#include <sstream>

struct LogEntry
{
    std::string address;
    std::string method;
    std::string uri;
    std::string user_agent;
    int response_code;

    std::string toString() {
        std::stringstream ss;
        ss << method << " " << response_code << " " << uri << " " << user_agent;
        return ss.str();
    }
};
