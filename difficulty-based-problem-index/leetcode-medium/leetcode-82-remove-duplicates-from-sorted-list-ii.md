# Leetcode 82 Remove Duplicates from Sorted List II

## Problem Statement

[https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/](https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/)

Given the `head` of a sorted linked list, _delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list_. Return _the linked list **sorted** as well_.

**Example 1:** ![](https://assets.leetcode.com/uploads/2021/01/04/linkedlist1.jpg)

```text
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
```

**Example 2:** ![](https://assets.leetcode.com/uploads/2021/01/04/linkedlist2.jpg)

```text
Input: head = [1,1,1,2,3]
Output: [2,3]
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
        ListNode *curr = head, *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        while(curr && curr->next)
        {
            if(curr->val == curr->next->val)
            {
                /* skip all nodes with same value */
                while(curr->next && curr->val == curr->next->val)
                    curr = curr->next;
                prev->next = curr->next;
            }
            else
                prev = curr;
                
            curr = curr->next;
        }
        return dummy->next;
    }
};
```

