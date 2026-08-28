#include <vector>
#include <unordered_map>
#include <algorithm>

struct ElementCount {
    int value = 0;
    int count = 0;
};

std::vector<int> top_k_frequent(const std::vector<int> & nums, int target_k) {
    std::unordered_map<int, int> count_map;

    for (auto & num : nums) {
        count_map[num]++;
    }

    std::vector<ElementCount> items = {};
    for (auto & pair : count_map) {
        ElementCount item;
        item.value = pair.first;
        item.count = pair.second;
        items.push_back(item);
    }

    // Sort by count descending
    std::sort(items.begin(), items.end(), [](const ElementCount & first, const ElementCount & second) {
        return first.count > second.count;
    });

    std::vector<int> output = {};
    for (int i = 0; i < target_k; i++) {
        output.push_back(items[i].value);
    }

    return output;
}
