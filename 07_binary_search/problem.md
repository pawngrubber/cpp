# Binary Search

Given an array of integers `nums` which is sorted in ascending order, and an integer `target`, write a function to search `target` in `nums`. If `target` exists, then return its index. Otherwise, return `-1`.

You must write an algorithm with $O(\log n)$ runtime complexity.

## Function

Implement in `solution.cpp`:

```cpp
#include <vector>

int binary_search(const std::vector<int>& nums, int target);
```

## Examples

| `nums` | `target` | Output |
| --- | --- | --- |
| `[-1, 0, 3, 5, 9, 12]` | `9` | `4` |
| `[-1, 0, 3, 5, 9, 12]` | `2` | `-1` |
