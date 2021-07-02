# Leetcode 105 Construct Binary Tree from Preorder and Inorder Traversal

## Problem Statement

[https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/](https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/)

Given two integer arrays `preorder` and `inorder` where `preorder` is the preorder traversal of a binary tree and `inorder` is the inorder traversal of the same tree, construct and return _the binary tree_.

**Example 1:** ![](https://assets.leetcode.com/uploads/2021/02/19/tree.jpg)

```text
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
```

**Example 2:**

```text
Input: preorder = [-1], inorder = [-1]
Output: [-1]
```

**Constraints:**

* `1 <= preorder.length <= 3000`
* `inorder.length == preorder.length`
* `-3000 <= preorder[i], inorder[i] <= 3000`
* `preorder` and `inorder` consist of **unique** values.
* Each value of `inorder` also appears in `preorder`.
* `preorder` is **guaranteed** to be the preorder traversal of the tree.
* `inorder` is **guaranteed** to be the inorder traversal of the tree.

## Solution

```cpp
class Solution {
public:
    int preorder_index;
    map<int,int> inorder_map;
    
    TreeNode* make_tree(vector<int>& preorder, int left, int right){
        if(left > right)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[preorder_index++]);
        root->left = make_tree(preorder, left, inorder_map[root->val]-1);
        root->right = make_tree(preorder, inorder_map[root->val]+1, right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorder_index = 0;
        for(int i = 0; i < inorder.size(); i++)
            inorder_map[inorder[i]] = i;
        
        return make_tree(preorder, 0, preorder.size()-1);
    }
};
```

