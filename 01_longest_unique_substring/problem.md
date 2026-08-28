# Longest Run of Unique Characters

Given a string, find the length of the longest contiguous substring that has no repeated characters.

A substring is contiguous — `abc` is a substring of `abcabcbb`, but `acb` is not.

## Function

Implement in `solution.cpp`:

```cpp
int count(std::string key);
```

Returns the length of the longest substring of `key` with no repeated characters.

## Examples

| `key` | Output |
| --- | --- |
| `abcabcbb` | `3` |
| `bbbbb` | `1` |
| `pwwkew` | `3` |
| (empty string) | `0` |
| `dvdf` | `3` |
| `abba` | `2` |
