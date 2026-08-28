#include <iostream>
#include <vector>
#include <string>

int max_sub_array(const std::vector<int>& nums);

struct TestCase {
    std::vector<int> nums;
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
        {{-2, 1, -3, 4, -1, 2, 1, -5, 4}, 6},
        {{1}, 1},
        {{5, 4, -1, 7, 8}, 23},
        {{-1}, -1},
        {{-5, -2, -3}, -2},
    };

    int pass = 0;
    int total = 0;

    for (const auto& tc : cases) {
        total++;
        int actual = max_sub_array(tc.nums);
        bool ok = (actual == tc.expected);
        pass += ok;
        std::cout << (ok ? "PASS" : "FAIL")
                  << "  nums=" << format_vec(tc.nums)
                  << "  expected " << tc.expected
                  << "  got " << actual << "\n";
    }
    std::cout << pass << "/" << total << " tests passed\n";
    return 0;
}
