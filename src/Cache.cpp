#include "Cache.h"

#include <utility>
#include "hiredis/hiredis.h"

Cache::Cache(const std::string& host, int port) {
    this->context = redisConnect(host.c_str(), port);
}

void Cache::blacklist(const std::string& actor, const std::string& reason) {
    redisCommand(context, "REPSHEET.BLACKLIST %s %s", actor.c_str(), reason.c_str());
}

void Cache::mark(const std::string &actor, const std::string &reason) {
    redisCommand(context, "REPSHEET.MARK %s %s", actor.c_str(), reason.c_str());
}

void Cache::record_request(const std::string& actor, const std::string& entry) {
    redisCommand(context, "RPUSH %s:repsheet:requests %s", actor.c_str(), entry.c_str());
}
