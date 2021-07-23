# Leetcode 814 Binary Tree Pruning

## Problem Statement

[https://leetcode.com/problems/binary-tree-pruning/](https://leetcode.com/problems/binary-tree-pruning/)

Given the `root` of a binary tree, return _the same tree where every subtree \(of the given tree\) not containing a_ `1` _has been removed_.

A subtree of a node `node` is `node` plus every node that is a descendant of `node`.

**Example 1:** ![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/06/1028_2.png)

```text
Input: root = [1,null,0,0,1]
Output: [1,null,0,null,1]
Explanation: 
Only the red nodes satisfy the property "every subtree not containing a 1".
The diagram on the right represents the answer.
```

**Example 2:** ![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/06/1028_1.png)

```text
Input: root = [1,0,1,0,0,0,1]
Output: [1,null,1,null,1]
```

**Example 3:** ![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/04/05/1028.png)

```text
Input: root = [1,1,0,1,1,0,1,0]
Output: [1,1,0,1,1,null,1]
```

**Constraints:**

* The number of nodes in the tree is in the range `[1, 200]`.
* `Node.val` is either `0` or `1`.

## Solution

### My Approach

```cpp
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root == nullptr)
            return root;
        
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        
        if(root->left || root->right || root->val)
            return root;
        
        return nullptr;
    }
};
```

