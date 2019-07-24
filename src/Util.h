#pragma once

#include <string>
#include <vector>
#include "Actor.h"
#include "Callbacks.h"

class Util {
public:
    static std::string join_string(std::vector<std::string> const &elements, const char *delimiter);
    static std::vector<std::string> collect_files(const std::string& path);
    static void process_files(const std::vector<std::string>& files,
                              const LogEntryCallback& success_callback,
                              const InvalidEntryCallback& error_callback);
    static void process_file(const std::string& file,
                             const LogEntryCallback& success_callback,
                             const InvalidEntryCallback& error_callback);
};
