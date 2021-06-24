# Leetcode 328 Odd Even Linked List

## Problem Statement

[https://leetcode.com/problems/odd-even-linked-list/](https://leetcode.com/problems/odd-even-linked-list/)

Given the `head` of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return _the reordered list_.

The **first** node is considered **odd**, and the **second** node is **even**, and so on.

Note that the relative order inside both the even and odd groups should remain as it was in the input.

**Example 1:** ![](https://assets.leetcode.com/uploads/2021/03/10/oddeven-linked-list.jpg)

```text
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
```

**Example 2:** ![](https://assets.leetcode.com/uploads/2021/03/10/oddeven2-linked-list.jpg)

```text
Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
```

**Constraints:**

* The number of nodes in the linked list is in the range `[0, 10^4]`.
* `-10^6 <= Node.val <= 10^6`

## Solution

```cpp
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head == nullptr)
            return head;
        ListNode *odd = head, *even = head->next, *first_even = head->next;
        while(even && even->next)
        {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = first_even;
        return head;
    }
};
```

