# Maximum Subarray

Given an integer array `nums`, find the subarray with the largest sum, and return its sum.

A subarray is a contiguous non-empty sequence of elements within an array.

## Function

Implement in `solution.cpp`:

```cpp
#include <vector>

int max_sub_array(const std::vector<int>& nums);
```

## Examples

| `nums` | Output |
| --- | --- |
| `[-2, 1, -3, 4, -1, 2, 1, -5, 4]` | `6` |
| `[1]` | `1` |
| `[5, 4, -1, 7, 8]` | `23` |
