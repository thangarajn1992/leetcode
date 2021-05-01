# Leetcode 234 Palindrome Linked List

## Problem Statement

[https://leetcode.com/problems/palindrome-linked-list/](https://leetcode.com/problems/palindrome-linked-list/)

Given the `head` of a singly linked list, return `true` if it is a palindrome.

**Example 1:** ![](https://assets.leetcode.com/uploads/2021/03/03/pal1linked-list.jpg)

```text
Input: head = [1,2,2,1]
Output: true
```

**Example 2:** ![](https://assets.leetcode.com/uploads/2021/03/03/pal2linked-list.jpg)

```text
Input: head = [1,2]
Output: false
```

**Constraints:**

* The number of nodes in the list is in the range `[1, 10^5]`.
* `0 <= Node.val <= 9`

  **Follow up:** Could you do it in `O(n)` time and `O(1)` space?

## Solution: 0\(n\) time and 0\(1\) space complexity

```cpp
class Solution {
public:
    bool isPalindromeUtil(ListNode **left, ListNode *right)
    {
        if(right == NULL)
            return 1;
        if(isPalindromeUtil(left, right->next))
        {
            if((*left)->val == right->val){
                (*left) = (*left)->next;
                return 1;
            }
        }
        return 0;
    }
    
    bool isPalindrome(ListNode* head) {
        return isPalindromeUtil(&head, head);
    }
};
```

