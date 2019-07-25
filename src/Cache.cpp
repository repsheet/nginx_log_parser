#include <hiredis/hiredis.h>
#include <vector>
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

void Cache::flush_requests() {
    auto *reply = static_cast<redisReply *>(redisCommand(context, "KEYS *:repsheet:ip:requests"));
    size_t i;
    std::vector<std::string> keys;
    if (reply && reply->type == REDIS_REPLY_ARRAY) {
        for (i = 0; i < reply->elements; i++) {
            keys.emplace_back(reply->str);
        }
        freeReplyObject(reply);
    }

    for (auto &key : keys) {
        redisCommand(context, "DEL %s", key.c_str());
    }
}
