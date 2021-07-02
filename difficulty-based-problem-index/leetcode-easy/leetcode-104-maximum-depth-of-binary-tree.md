# Leetcode 104 Maximum Depth of Binary Tree

## Problem Statement

[https://leetcode.com/problems/maximum-depth-of-binary-tree/](https://leetcode.com/problems/maximum-depth-of-binary-tree/)

Given the `root` of a binary tree, return _its maximum depth_.

A binary tree's **maximum depth** is the number of nodes along the longest path from the root node down to the farthest leaf node.

**Example 1:** ![](https://assets.leetcode.com/uploads/2020/11/26/tmp-tree.jpg)

```text
Input: root = [3,9,20,null,null,15,7]
Output: 3
```

**Example 2:**

```text
Input: root = [1,null,2]
Output: 2
```

**Example 3:**

```text
Input: root = []
Output: 0
```

**Example 4:**

```text
Input: root = [0]
Output: 1
```

**Constraints:**

* The number of nodes in the tree is in the range `[0, 10^4]`.
* `-100 <= Node.val <= 100`

## Solution

```cpp
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
```

