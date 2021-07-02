# Leetcode 109 Convert Sorted List to Binary Search Tree

## Problem Statement

[https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/](https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/)

Given the `head` of a singly linked list where elements are **sorted in ascending order**, convert it to a height balanced BST.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of _every_ node never differs by more than 1.

**Example 1:** ![](https://assets.leetcode.com/uploads/2020/08/17/linked.jpg)

```text
Input: head = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: 
One possible answer is [0,-3,9,-10,null,5], which represents the shown 
height balanced BST.
```

**Example 2:**

```text
Input: head = []
Output: []
```

**Example 3:**

```text
Input: head = [0]
Output: [0]
```

**Example 4:**

```text
Input: head = [1,3]
Output: [3,1]
```

**Constraints:**

* The number of nodes in `head` is in the range `[0, 2 * 10^4]`.
* `-10^5 <= Node.val <= 10^5`

## Solution

```cpp
class Solution {
public:
    TreeNode* sortedListToBSTUtil(ListNode *head, ListNode *tail)
    {
        if(head == tail)
            return NULL;
        ListNode *fast = head, *slow = head;
        while(fast != tail && fast->next != tail)
        {
            slow = slow->next;
            fast = fast->next->next;
        }    
        TreeNode *root = new TreeNode(slow->val);
        root->left = sortedListToBSTUtil(head, slow);
        root->right = sortedListToBSTUtil(slow->next, tail);
        
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        return sortedListToBSTUtil(head, NULL);
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
```

