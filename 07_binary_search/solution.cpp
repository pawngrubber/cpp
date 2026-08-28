#include <vector>

int search_recursive(const std::vector<int> & nums, int target, int bottom_idx, int top_idx) {
    int mid_idx = bottom_idx + (top_idx - bottom_idx) / 2;

    if (nums[mid_idx] == target) {
        return mid_idx;
    }
    else if (bottom_idx == mid_idx) {
        return -1;
    }
    else if (nums[mid_idx] < target) {
        return search_recursive(nums, target, mid_idx, top_idx);
    }
    else {
        return search_recursive(nums, target, bottom_idx, mid_idx);
    }
}

int binary_search(const std::vector<int> & nums, int target) {
    return search_recursive(nums, target, 0, (int)nums.size());
}
