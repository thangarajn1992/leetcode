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

### Iterative Approach

```cpp
class Solution {
public:
    /* Iterative Approach */
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
         int preIndex = 0;
         int inIndex = 0;
         bool rightSubTree = false;
         TreeNode *prev = new TreeNode(preorder[preIndex]);
         TreeNode *root = prev;
         preIndex++;
         
         stack<TreeNode*> s;
         s.push(root);
         
         while(preIndex < preorder.size())
         {
             if(s.empty() == false && inorder[inIndex] == s.top()->val)
             {
                 prev = s.top(); s.pop();
                 inIndex++;
                 rightSubTree = true;
             }
             else
             {
                 TreeNode *node = new TreeNode(preorder[preIndex]);
                 preIndex++;
                 s.push(node);
                 if(rightSubTree == true)
                 {
                     prev->right = node;
                     prev = prev->right;
                     rightSubTree = false;
                 }
                 else
                 {
                     prev->left = node;
                     prev = prev->left;
                 } 
             }
         }
         return root;
     } 
 };
```

### Recursive Approach

```cpp
class Solution {
public:
    int preorderIndex;
    map<int,int> inorderIndices;
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        preorderIndex = 0;
        for(int i = 0; i < inorder.size(); i++)
            inorderIndices[inorder[i]] = i;
        
        return makeTree(preorder, 0, preorder.size()-1);
    }  
     
    TreeNode* makeTree(vector<int>& preorder, int left, int right){
        if(left > right)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[preorderIndex++]);
        root->left = makeTree(preorder, left, inorderIndices[root->val]-1);
        root->right = makeTree(preorder, inorderIndices[root->val]+1, right);
        return root;
    }

};
```

