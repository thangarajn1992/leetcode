# Leetcode 106 Construct Binary Tree from Inorder and Postorder Traversal

## Problem Statement

[https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/](https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/)

Given two integer arrays `inorder` and `postorder` where `inorder` is the inorder traversal of a binary tree and `postorder` is the postorder traversal of the same tree, construct and return _the binary tree_.

**Example 1:** ![](https://assets.leetcode.com/uploads/2021/02/19/tree.jpg)

```text
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
```

**Example 2:**

```text
Input: inorder = [-1], postorder = [-1]
Output: [-1]
```

**Constraints:**

* `1 <= inorder.length <= 3000`
* `postorder.length == inorder.length`
* `-3000 <= inorder[i], postorder[i] <= 3000`
* `inorder` and `postorder` consist of **unique** values.
* Each value of `postorder` also appears in `inorder`.
* `inorder` is **guaranteed** to be the inorder traversal of the tree.
* `postorder` is **guaranteed** to be the postorder traversal of the tree.

## Solution

```cpp
class Solution {
public:
    map<int,int> inorder_map;
    int postorder_index;
    TreeNode* make_tree(vector<int>& postorder, int left, int right)
    {
        if(left > right)
            return nullptr;
        TreeNode *root = new TreeNode(postorder[postorder_index--]);
        root->right = make_tree(postorder, inorder_map[root->val] + 1, right);
        root->left = make_tree(postorder, left, inorder_map[root->val] - 1);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int size = postorder.size();
        postorder_index = size - 1;
        for(int i = 0; i < size; i++)
            inorder_map[inorder[i]] = i;
        return make_tree(postorder, 0, size - 1);
    }
};
```

