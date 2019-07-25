#include <hiredis/hiredis.h>
#include "Cache.h"

#define CACHE_EXPIRY 86400

Cache::Cache(const std::string& host, int port) {
    this->context = redisConnect(host.c_str(), port);
}

void Cache::blacklist(const std::string& actor, const std::string& reason) {
    redisCommand(context, "REPSHEET.BLACKLIST %s %s %d", actor.c_str(), reason.c_str(), CACHE_EXPIRY);
}

void Cache::record_request(const std::string& actor, const std::string& entry) {
    redisCommand(context, "RPUSH %s:repsheet:requests %s", actor.c_str(), entry.c_str());
}
