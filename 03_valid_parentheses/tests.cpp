#include <iostream>
#include <string>
#include <vector>

bool is_valid(std::string s);

struct TestCase {
    std::string s;
    bool expected;
};

int main() {
    std::vector<TestCase> cases = {
        {"()", true},
        {"()[]{}", true},
        {"(]", false},
        {"([)]", false},
        {"{[]}", true},
        {"", true},
        {"[", false},
        {"]", false},
    };

    int pass = 0;
    int total = 0;

    for (const auto& tc : cases) {
        total++;
        bool actual = is_valid(tc.s);
        bool ok = (actual == tc.expected);
        pass += ok;
        std::cout << (ok ? "PASS" : "FAIL")
                  << "  \"" << tc.s << "\""
                  << "  expected " << (tc.expected ? "true" : "false")
                  << "  got " << (actual ? "true" : "false") << "\n";
    }
    std::cout << pass << "/" << total << " tests passed\n";
    return 0;
}
