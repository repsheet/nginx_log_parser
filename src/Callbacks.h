#pragma once

#include <functional>
#include <unordered_map>
#include "Actor.h"

using LogEntryCallback = std::function<void(LogEntry)>;
using InvalidEntryCallback = std::function<void(InvalidEntry)>;

class Callbacks {
public:
    static InvalidEntryCallback add_invalid_request(Actors &actors);
    static LogEntryCallback add_request(Actors &actors);
};