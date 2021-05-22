# Leetcode 61 Rotate List

## Problem Statement

[https://leetcode.com/problems/rotate-list/](https://leetcode.com/problems/rotate-list/)

Given the `head` of a linked list, rotate the list to the right by `k` places.

**Example 1:** ![](https://assets.leetcode.com/uploads/2020/11/13/rotate1.jpg)

```text
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
```

**Example 2:** ![](https://assets.leetcode.com/uploads/2020/11/13/roate2.jpg)

```text
Input: head = [0,1,2], k = 4
Output: [2,0,1]
```

**Constraints:**

* The number of nodes in the list is in the range `[0, 500]`.
* `-100 <= Node.val <= 100`
* `0 <= k <= 2 * 10^9`

## Solution

```cpp
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !k) return head;
        int total_nodes = 0;
        ListNode *temp  = head;
        for(; temp; temp = temp->next)
            total_nodes++;
        k = k % total_nodes;
        for(int i = 0; i < k; i++)
        {
            ListNode* prev = head;
            temp = head->next;
            while(temp->next!=NULL)
            {
                prev = prev->next;
                temp = temp->next;
            }
            prev->next = NULL;
            temp->next = head;
            head = temp;
        }
        return head;        
    }
};
```

