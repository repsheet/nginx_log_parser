#pragma once

#include <string>
#include <vector>

class Parser {
public:
    static std::string get_user_agent(std::vector<std::string> parts);
    static bool is_valid_method(const std::string& method);
    static bool is_valid_response_code(int response_code);
    static bool is_valid_request(const std::string& method, int response_code);
    static int parse_response_code(const std::string& code);
};
