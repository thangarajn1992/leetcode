# LeetCode 86 Partition List

## Problem Statement

[https://leetcode.com/problems/partition-list/](https://leetcode.com/problems/partition-list/)

Given the `head` of a linked list and a value `x`, partition it such that all nodes **less than** `x` come before nodes **greater than or equal** to `x`.

You should **preserve** the original relative order of the nodes in each of the two partitions.

**Example 1:** ![](https://assets.leetcode.com/uploads/2021/01/04/partition.jpg)

```text
Input: head = [1,4,3,2,5,2], x = 3
Output: [1,2,2,4,3,5]
```

**Example 2:**

```text
Input: head = [2,1], x = 2
Output: [1,2]
```

**Constraints:**

* The number of nodes in the list is in the range `[0, 200]`.
* `-100 <= Node.val <= 100`
* `-200 <= x <= 200`

## Solution

```cpp
ListNode* partition(ListNode* head, int x) {
    ListNode *large = head;
    ListNode *bef_large = NULL, *temp = NULL, *prev = NULL, *next = NULL;
    while(large && large->val < x){
        bef_large = large;
        large = large->next;
    }
    temp = large;
    prev = bef_large;
    while(temp) {
        cout << endl;
        if(temp->val < x) {
            next = temp->next;
            if(bef_large == NULL)
            {
                bef_large = temp;
                if(prev == NULL)
                    prev = large;
                head = bef_large;
                head->next = large;
            }
            else
            {
                bef_large->next = temp; 
                temp->next = large;
            }
            bef_large = temp;
            temp = next;
            prev->next = next;
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}
```

