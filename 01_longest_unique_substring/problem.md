# Longest Run of Unique Characters

Given a string, find the length of the longest contiguous substring that has no repeated characters.

A substring is contiguous — `abc` is a substring of `abcabcbb`, but `acb` is not.

## Input

A single line on stdin: the string to check. It may be empty.

## Output

A single integer on stdout: the length of the longest substring with no repeated characters.

## Examples

| Input | Output |
| --- | --- |
| `abcabcbb` | `3` |
| `bbbbb` | `1` |
| `pwwkew` | `3` |
| (empty) | `0` |
| `dvdf` | `3` |
| `abba` | `2` |
