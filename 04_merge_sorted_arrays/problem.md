# Merge Sorted Arrays

Given two sorted integer arrays `nums1` and `nums2`, merge them into a single sorted array.

## Function

Implement in `solution.cpp`:

```cpp
#include <vector>

std::vector<int> merge_sorted(const std::vector<int>& nums1, const std::vector<int>& nums2);
```

## Examples

| `nums1` | `nums2` | Output |
| --- | --- | --- |
| `[1, 2, 3]` | `[2, 5, 6]` | `[1, 2, 2, 3, 5, 6]` |
| `[1]` | `[]` | `[1]` |
| `[]` | `[0]` | `[0]` |
