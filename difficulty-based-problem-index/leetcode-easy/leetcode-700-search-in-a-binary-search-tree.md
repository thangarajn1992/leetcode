# Leetcode 700 Search in a Binary Search Tree

## Problem Statement

[https://leetcode.com/problems/search-in-a-binary-search-tree/](https://leetcode.com/problems/search-in-a-binary-search-tree/)

You are given the `root` of a binary search tree \(BST\) and an integer `val`.

Find the node in the BST that the node's value equals `val` and return the subtree rooted with that node. If such a node does not exist, return `null`.

**Example 1:** ![](https://assets.leetcode.com/uploads/2021/01/12/tree1.jpg)

```text
Input: root = [4,2,7,1,3], val = 2
Output: [2,1,3]
```

**Example 2:** ![](https://assets.leetcode.com/uploads/2021/01/12/tree2.jpg)

```text
Input: root = [4,2,7,1,3], val = 5
Output: []
```

**Constraints:**

* The number of nodes in the tree is in the range `[1, 5000]`.
* `1 <= Node.val <= 10^7`
* `root` is a binary search tree.
* `1 <= val <= 10^7`

## Solution

### Recursive Approach

```cpp
class Solution {
public:
    /* Recursive Solution */
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr)
            return nullptr;
        
        if(root->val == val)
            return root;
        
        if(root->val < val)
            return searchBST(root->right, val);
        else
            return searchBST(root->left, val);
    }
};
```

### Iterative Approach

```cpp
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root != nullptr)
        {
            if(root->val == val)
                return root;
            if(root->val < val)
                root = root->right;
            else
                root = root->left;
        }
        return root;
    }
};
```
