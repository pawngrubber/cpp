#include <iostream>
#include <vector>
#include <string>

std::vector<int> merge_sorted(const std::vector<int>& nums1, const std::vector<int>& nums2);

struct TestCase {
    std::vector<int> nums1;
    std::vector<int> nums2;
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
        {{1, 2, 3}, {2, 5, 6}, {1, 2, 2, 3, 5, 6}},
        {{1}, {}, {1}},
        {{}, {0}, {0}},
        {{4, 5, 6}, {1, 2, 3}, {1, 2, 3, 4, 5, 6}},
        {{}, {}, {}},
    };

    int pass = 0;
    int total = 0;

    for (const auto& tc : cases) {
        total++;
        std::vector<int> actual = merge_sorted(tc.nums1, tc.nums2);
        bool ok = (actual == tc.expected);
        pass += ok;
        std::cout << (ok ? "PASS" : "FAIL")
                  << "  nums1=" << format_vec(tc.nums1)
                  << "  nums2=" << format_vec(tc.nums2)
                  << "  expected " << format_vec(tc.expected)
                  << "  got " << format_vec(actual) << "\n";
    }
    std::cout << pass << "/" << total << " tests passed\n";
    return 0;
}
