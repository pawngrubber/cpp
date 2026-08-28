#include <iostream>
#include <string>
#include <vector>

bool is_anagram(std::string s, std::string t);

struct TestCase {
    std::string s;
    std::string t;
    bool expected;
};

int main() {
    std::vector<TestCase> cases = {
        {"anagram", "nagaram", true},
        {"rat", "car", false},
        {"a", "a", true},
        {"ab", "a", false},
        {"listen", "silent", true},
        {"", "", true},
    };

    int pass = 0;
    int total = 0;

    for (const auto& tc : cases) {
        total++;
        bool actual = is_anagram(tc.s, tc.t);
        bool ok = (actual == tc.expected);
        pass += ok;
        std::cout << (ok ? "PASS" : "FAIL")
                  << "  s=\"" << tc.s << "\" t=\"" << tc.t << "\""
                  << "  expected " << (tc.expected ? "true" : "false")
                  << "  got " << (actual ? "true" : "false") << "\n";
    }
    std::cout << pass << "/" << total << " tests passed\n";
    return 0;
}
