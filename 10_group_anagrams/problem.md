# Group Anagrams

Given an array of strings `strs`, group the anagrams together. You can return the answer in any order.

An anagram is a word formed by rearranging the letters of another word, using all the original letters exactly once.

## Function

Implement in `solution.cpp`:

```cpp
#include <vector>
#include <string>

std::vector<std::vector<std::string>> group_anagrams(const std::vector<std::string>& strs);
```

## Examples

| `strs` | Output |
| --- | --- |
| `["eat", "tea", "tan", "ate", "nat", "bat"]` | `[["bat"], ["nat", "tan"], ["ate", "eat", "tea"]]` |
| `[""]` | `[[""]]` |
| `["a"]` | `[["a"]]` |
