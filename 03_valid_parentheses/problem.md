# Valid Parentheses

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:
1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.

## Function

Implement in `solution.cpp`:

```cpp
#include <string>

bool is_valid(std::string s);
```

## Examples

| `s` | Output |
| --- | --- |
| `()` | `true` |
| `()[]{}` | `true` |
| `(]` | `false` |
| `([)]` | `false` |
| `{[]}` | `true` |
