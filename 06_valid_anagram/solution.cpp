#include <string>
#include <unordered_map>

bool is_anagram(std::string first_str, std::string second_str) {
    std::unordered_map<char, int> count_map;

    for (auto & chr : first_str) {
        count_map[chr]++; // Initializes to zero
    }

    for (auto & chr : second_str) {
        if (count_map.find(chr) == count_map.end()) {
            return false;
        }

        count_map[chr]--;

        if (count_map[chr] == 0) {
            count_map.erase(chr);
        }
    }

    return count_map.empty();
}
