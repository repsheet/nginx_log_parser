#include <sstream>
#include <iterator>
#include <dirent.h>
#include <cstring>
#include <fstream>
#include <filesystem>
#include "Util.h"
#include "Parser.h"

std::string Util::join_string(std::vector<std::string> const &elements, const char *const delimiter) {
    std::ostringstream os;
    auto b = begin(elements);
    auto e = end(elements);

    if (b != e) {
        std::copy(b, prev(e), std::ostream_iterator<std::string>(os, delimiter));
        b = prev(e);
    }

    if (b != e) {
        os << *b;
    }

    return os.str();
}

std::vector<std::string> Util::collect_files(const std::string &path) {
    std::vector<std::string> files;
    if (std::filesystem::exists(path)) {
        for (auto &file : std::filesystem::directory_iterator(path)) {
            files.push_back(file.path());
        }
    }
    return files;
}

void Util::process_file(const std::string& file,
                  const LogEntryCallback& success_callback,
                  const InvalidEntryCallback& error_callback)
{
    std::stringstream ss(file);
    std::ifstream in(ss.str());
    std::string line;

    while(getline(in, line)) {
        std::istringstream iss(line);
        std::string part;
        std::vector<std::string> parts;

        while (iss >> part) {
            parts.emplace_back(part);
        }

        auto method = parts[5].erase(0,1);
        auto response_code = Parser::parse_response_code(parts[8]);
        auto user_agent = Parser::get_user_agent(parts);

        if (!Parser::is_valid_request(method, response_code)) {
            error_callback(InvalidEntry{parts[0], line});
            continue;
        }

        success_callback(LogEntry{parts[0], method, parts[6], user_agent, response_code});
    }
}

void Util::process_files(const std::vector<std::string> &files,
                         const LogEntryCallback &success_callback,
                         const InvalidEntryCallback &error_callback) {
    for (auto &&file : files) {
        process_file(file, success_callback, error_callback);
    }
}
