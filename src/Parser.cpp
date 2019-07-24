#include <stdexcept>
#include "Parser.h"
#include "Util.h"

std::string Parser::get_user_agent(std::vector<std::string> parts) {
    std::string user_agent;

    try {
        std::vector<std::string> range;
        if (parts.size() > 11) {
            std::copy(std::begin(parts) + 11,
                      std::begin(parts) + parts.size(),
                      back_inserter(range));
            user_agent = Util::join_string(range, " ");
        }
    } catch (int n) {
        user_agent = "-";
    }

    return user_agent;
}

bool Parser::is_valid_method(const std::string &method) {
    return method == "GET"
           || method == "POST"
           || method == "HEAD"
           || method == "OPTIONS"
           || method == "CONNECT"
           || method == "PUT";
}

bool Parser::is_valid_response_code(int response_code) {
    return (response_code >= 100 && response_code < 600);
}

bool Parser::is_valid_request(const std::string &method, int response_code) {
    return (Parser::is_valid_method(method) && Parser::is_valid_response_code(response_code));
}

int Parser::parse_response_code(const std::string &code) {
    try {
        return std::stoi(code);
    } catch (std::invalid_argument &e) {
        return 0;
    }
}
