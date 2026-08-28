#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

std::vector<int> two_sum(const std::vector<int>& nums, int target);

struct TestCase {
    std::vector<int> nums;
    int target;
    std::vector<int> expected;
};

std::string format_vec(const std::vector<int>& v) {
    std::string s = "[";
    for (size_t i = 0; i < v.size(); ++i) {
        s += std::to_string(v[i]);
        if (i + 1 < v.size()) s += ", ";
    }
    s += "]";
    return s;
}

int main() {
    std::vector<TestCase> cases = {
        {{2, 7, 11, 15}, 9, {0, 1}},
        {{3, 2, 4}, 6, {1, 2}},
        {{3, 3}, 6, {0, 1}},
        {{-1, -2, -3, -4, -5}, -8, {2, 4}},
    };

    int pass = 0;
    int total = 0;

    for (const auto& tc : cases) {
        total++;
        std::vector<int> actual = two_sum(tc.nums, tc.target);
        std::sort(actual.begin(), actual.end());
        std::vector<int> expected = tc.expected;
        std::sort(expected.begin(), expected.end());

        bool ok = (actual == expected);
        pass += ok;
        std::cout << (ok ? "PASS" : "FAIL")
                  << "  nums=" << format_vec(tc.nums)
                  << "  target=" << tc.target
                  << "  expected " << format_vec(tc.expected)
                  << "  got " << format_vec(actual) << "\n";
    }
    std::cout << pass << "/" << total << " tests passed\n";
    return 0;
}
