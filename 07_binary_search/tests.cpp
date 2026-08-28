#include <iostream>
#include <vector>
#include <string>

int binary_search(const std::vector<int>& nums, int target);

struct TestCase {
    std::vector<int> nums;
    int target;
    int expected;
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
        {{-1, 0, 3, 5, 9, 12}, 9, 4},
        {{-1, 0, 3, 5, 9, 12}, 2, -1},
        {{5}, 5, 0},
        {{5}, -5, -1},
        {{1, 3, 5, 7, 9, 11}, 1, 0},
        {{1, 3, 5, 7, 9, 11}, 11, 5},
    };

    int pass = 0;
    int total = 0;

    for (const auto& tc : cases) {
        total++;
        int actual = binary_search(tc.nums, tc.target);
        bool ok = (actual == tc.expected);
        pass += ok;
        std::cout << (ok ? "PASS" : "FAIL")
                  << "  nums=" << format_vec(tc.nums)
                  << "  target=" << tc.target
                  << "  expected " << tc.expected
                  << "  got " << actual << "\n";
    }
    std::cout << pass << "/" << total << " tests passed\n";
    return 0;
}
