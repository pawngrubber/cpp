#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

std::vector<std::vector<std::string>> group_anagrams(const std::vector<std::string> & input_words) {
    std::unordered_map<std::string, std::vector<std::string>> groups_map;

    for (auto & word : input_words) {
        std::string sorted_word = word;
        std::sort(sorted_word.begin(), sorted_word.end());

        groups_map[sorted_word].push_back(word);
    }

    std::vector<std::vector<std::string>> output = {};
    for (auto & pair : groups_map) {
        output.push_back(pair.second);
    }

    return output;
}
