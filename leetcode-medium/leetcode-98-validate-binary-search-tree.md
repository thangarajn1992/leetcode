# LeetCode 98 Validate Binary Search Tree

## Problem Statement

[https://leetcode.com/problems/validate-binary-search-tree/](https://leetcode.com/problems/validate-binary-search-tree/)

Given the `root` of a binary tree, _determine if it is a valid binary search tree \(BST\)_.

A **valid BST** is defined as follows:

* The left subtree of a node contains only nodes with keys **less than** the node's key.
* The right subtree of a node contains only nodes with keys **greater than** the node's key.
* Both the left and right subtrees must also be binary search trees.

**Example 1:** ![](https://assets.leetcode.com/uploads/2020/12/01/tree1.jpg)

```text
Input: root = [2,1,3]
Output: true
```

**Example 2:** ![](https://assets.leetcode.com/uploads/2020/12/01/tree2.jpg)

```text
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
```

**Constraints:**

* The number of nodes in the tree is in the range `[1, 10^4]`.
* `-2^31 <= Node.val <= 2^31 - 1`

## Solution

```cpp
class Solution {
public:
    bool isValidBSTUtil(TreeNode* root, TreeNode *left, TreeNode *right)
    {
        if(!root)
            return 1;
        if( (left && left->val >= root->val) || (right && right->val <= root->val))
            return 0;
        return isValidBSTUtil(root->left, left, root) &&
                isValidBSTUtil(root->right, root, right);

    }
    bool isValidBST(TreeNode* root) {
        return isValidBSTUtil(root, NULL, NULL);
    }
};
```

