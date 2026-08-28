# Reverse Linked List

Given the head of a singly linked list, reverse the list, and return the reversed list.

## Function

Implement in `solution.cpp`:

```cpp
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* reverse_list(ListNode* head);
```

## Examples

| Input | Output |
| --- | --- |
| `[1, 2, 3, 4, 5]` | `[5, 4, 3, 2, 1]` |
| `[1, 2]` | `[2, 1]` |
| `[]` | `[]` |
