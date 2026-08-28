#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::vector<std::string>> group_anagrams(const std::vector<std::string>& strs);

std::vector<std::vector<std::string>> normalize(std::vector<std::vector<std::string>> groups) {
    for (auto& g : groups) {
        std::sort(g.begin(), g.end());
    }
    std::sort(groups.begin(), groups.end());
    return groups;
}

std::string format_groups(const std::vector<std::vector<std::string>>& groups) {
    std::string s = "[";
    for (size_t i = 0; i < groups.size(); ++i) {
        s += "[";
        for (size_t j = 0; j < groups[i].size(); ++j) {
            s += "\"" + groups[i][j] + "\"";
            if (j + 1 < groups[i].size()) s += ", ";
        }
        s += "]";
        if (i + 1 < groups.size()) s += ", ";
    }
    s += "]";
    return s;
}

struct TestCase {
    std::vector<std::string> strs;
    std::vector<std::vector<std::string>> expected;
};

int main() {
    std::vector<TestCase> cases = {
        {
            {"eat", "tea", "tan", "ate", "nat", "bat"},
            {{"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}}
        },
        {
            {""},
            {{""}}
        },
        {
            {"a"},
            {{"a"}}
        },
    };

    int pass = 0;
    int total = 0;

    for (const auto& tc : cases) {
        total++;
        auto actual = group_anagrams(tc.strs);
        bool ok = (normalize(actual) == normalize(tc.expected));
        pass += ok;
        std::cout << (ok ? "PASS" : "FAIL")
                  << "  expected " << format_groups(normalize(tc.expected))
                  << "  got " << format_groups(normalize(actual)) << "\n";
    }
    std::cout << pass << "/" << total << " tests passed\n";
    return 0;
}
