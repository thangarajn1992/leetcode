# Leetcode 206 Reverse Linked List

## Problem Statement

[https://leetcode.com/problems/reverse-linked-list/](https://leetcode.com/problems/reverse-linked-list/)

Given the `head` of a singly linked list, reverse the list, and return _the reversed list_.

**Example 1:** ![](https://assets.leetcode.com/uploads/2021/02/19/rev1ex1.jpg)

```text
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]
```

**Example 2:** ![](https://assets.leetcode.com/uploads/2021/02/19/rev1ex2.jpg)

```text
Input: head = [1,2]
Output: [2,1]
```

**Example 3:**

```text
Input: head = []
Output: []
```

**Constraints:**

* The number of nodes in the list is the range `[0, 5000]`.
* `-5000 <= Node.val <= 5000`

## Solution

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev = nullptr, *curr = head, *next = nullptr;
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
```

