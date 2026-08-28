# Valid Anagram

Given two strings `s` and `t`, return `true` if `t` is an anagram of `s`, and `false` otherwise.

An anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

## Function

Implement in `solution.cpp`:

```cpp
#include <string>

bool is_anagram(std::string s, std::string t);
```

## Examples

| `s` | `t` | Output |
| --- | --- | --- |
| `anagram` | `nagaram` | `true` |
| `rat` | `car` | `false` |
