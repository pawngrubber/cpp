#include <vector>

int max_sub_array(const std::vector<int> & nums) {
    int best_sum = nums[0];
    int current_sum = 0;

    for (auto & num : nums) {
        current_sum += num;

        if (current_sum > best_sum) {
            best_sum = current_sum;
        }

        if (current_sum < 0) {
            current_sum = 0;
        }
    }

    return best_sum;
}
