# Leetcode 83 Remove Duplicates from Sorted List

## Problem Statement

[https://leetcode.com/problems/remove-duplicates-from-sorted-list/](https://leetcode.com/problems/remove-duplicates-from-sorted-list/)

Given the `head` of a sorted linked list, _delete all duplicates such that each element appears only once_. Return _the linked list **sorted** as well_.

**Example 1:** ![](https://assets.leetcode.com/uploads/2021/01/04/list1.jpg)

```text
Input: head = [1,1,2]
Output: [1,2]
```

**Example 2:** ![](https://assets.leetcode.com/uploads/2021/01/04/list2.jpg)

```text
Input: head = [1,1,2,3,3]
Output: [1,2,3]
```

**Constraints:**

* The number of nodes in the list is in the range `[0, 300]`.
* `-100 <= Node.val <= 100`
* The list is guaranteed to be **sorted** in ascending order.

## Solution

```cpp
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return head;
        ListNode *curr = head;
        while(curr->next)
        {
            if(curr->val == curr->next->val)
                curr->next = curr->next->next;
            else
                curr = curr->next;
        }
        return head;
    }
};
```

