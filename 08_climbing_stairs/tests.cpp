#include <iostream>
#include <vector>

int climb_stairs(int n);

struct TestCase {
    int n;
    int expected;
};

int main() {
    std::vector<TestCase> cases = {
        {1, 1},
        {2, 2},
        {3, 3},
        {4, 5},
        {5, 8},
        {10, 89},
    };

    int pass = 0;
    int total = 0;

    for (const auto& tc : cases) {
        total++;
        int actual = climb_stairs(tc.n);
        bool ok = (actual == tc.expected);
        pass += ok;
        std::cout << (ok ? "PASS" : "FAIL")
                  << "  n=" << tc.n
                  << "  expected " << tc.expected
                  << "  got " << actual << "\n";
    }
    std::cout << pass << "/" << total << " tests passed\n";
    return 0;
}
