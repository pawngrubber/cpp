#include <string>
#include <vector>
#include <unordered_map>

bool is_valid(std::string str) {
    std::vector<char> stack = {};
    std::unordered_map<char, char> pairs = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for (auto & chr : str) {
        if (pairs.find(chr) != pairs.end()) {
            if (stack.empty()) {
                return false;
            }

            char last_char = stack.back();
            char expected_open = pairs[chr];

            if (last_char != expected_open) {
                return false;
            }

            stack.pop_back();
        }
        else {
            stack.push_back(chr);
        }
    }

    return stack.empty();
}

