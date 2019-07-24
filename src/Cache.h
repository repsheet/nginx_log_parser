#pragma once

#include <string>
#include <hiredis/hiredis.h>
#include "LogEntry.h"

class Cache {
public:
    Cache(const std::string& host, int port);
    void blacklist(const std::string& actor, const std::string& reason);
    void mark(const std::string& actor, const std::string& reason);
    void record_request(const std::string& actor, const std::string& entry);
private:
    redisContext *context;
};
