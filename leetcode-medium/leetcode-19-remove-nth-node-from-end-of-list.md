# Leetcode 19 Remove Nth Node From End of List

## Problem Statement

[https://leetcode.com/problems/remove-nth-node-from-end-of-list/](https://leetcode.com/problems/remove-nth-node-from-end-of-list/)

Given the `head` of a linked list, remove the `nth` node from the end of the list and return its head.

**Follow up:** Could you do this in one pass?

**Example 1:** ![](https://assets.leetcode.com/uploads/2020/10/03/remove_ex1.jpg)

```text
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
```

**Example 2:**

```text
Input: head = [1], n = 1
Output: []
```

**Example 3:**

```text
Input: head = [1,2], n = 1
Output: [1]
```

**Constraints:**

* The number of nodes in the list is `sz`.
* `1 <= sz <= 30`
* `0 <= Node.val <= 100`
* `1 <= n <= sz`

## Solution

```cpp
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy = ListNode(0);
        dummy.next = head;
        ListNode *first = &dummy, *second = &dummy;
        for(int i=0; i<=n; i++) {
            first = first->next;
        }
        while(first) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return dummy.next;
    }
};
```

