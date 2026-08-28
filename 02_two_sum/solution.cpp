#include <vector>
#include <unordered_map>

std::vector<int> two_sum(const std::vector<int> & nums, int target) {
    std::unordered_map<int, int> seen_map;

    for (int i = 0, len = (int)nums.size(); i < len; i++) {
        int current = nums[i];
        int complement = target - current;

        // Check if the complement was already seen
        if (seen_map.find(complement) != seen_map.end()) { // use .find() to check existence
            return {seen_map[complement], i};
        }

        // Store the current number's value as key, and its index as value
        seen_map[current] = i;
    }

    return {};
}
