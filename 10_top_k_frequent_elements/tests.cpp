#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

std::vector<int> top_k_frequent(const std::vector<int>& nums, int k);

struct TestCase {
    std::vector<int> nums;
    int k;
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
        {{1, 1, 1, 2, 2, 3}, 2, {1, 2}},
        {{1}, 1, {1}},
        {{4, 1, -1, 2, -1, 2, 3}, 2, {-1, 2}},
    };

    int pass = 0;
    int total = 0;

    for (const auto& tc : cases) {
        total++;
        std::vector<int> actual = top_k_frequent(tc.nums, tc.k);
        std::sort(actual.begin(), actual.end());
        std::vector<int> expected = tc.expected;
        std::sort(expected.begin(), expected.end());

        bool ok = (actual == expected);
        pass += ok;
        std::cout << (ok ? "PASS" : "FAIL")
                  << "  nums=" << format_vec(tc.nums)
                  << "  k=" << tc.k
                  << "  expected " << format_vec(tc.expected)
                  << "  got " << format_vec(actual) << "\n";
    }
    std::cout << pass << "/" << total << " tests passed\n";
    return 0;
}
