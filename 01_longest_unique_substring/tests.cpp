#include <iostream>
#include <string>
#include <unordered_map>

int count(std::string key);  // defined in solution.cpp

std::unordered_map<std::string, int> tests(){
    std::unordered_map<std::string, int> foo;
    foo["abcabcbb"] = 3;
    foo["bbbbb"] = 1;
    foo["pwwkew"] = 3;
    foo[""] = 0;
    foo["dvdf"] = 3;
    foo["abba"] = 2;
    return foo;
}

int main(){
    int pass = 0;
    int total = 0;
    for (const auto & [key, expected] : tests()) {
        total++;
        int actual = count(key);
        bool ok = actual == expected;
        pass += ok;
        std::cout << (ok ? "PASS" : "FAIL")
                   << "  \"" << key << "\""
                   << "  expected " << expected
                   << "  got " << actual << "\n";
    }
    std::cout << pass << "/" << total << " tests passed\n";
    return 0;
}
