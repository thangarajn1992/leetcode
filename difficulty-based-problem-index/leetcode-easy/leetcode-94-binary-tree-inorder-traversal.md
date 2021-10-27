# Leetcode 94 Binary Tree Inorder Traversal

## Problem Statement

[https://leetcode.com/problems/binary-tree-inorder-traversal/](https://leetcode.com/problems/binary-tree-inorder-traversal/)

Given the `root` of a binary tree, return _the inorder traversal of its nodes' values_.

**Example 1:** ![](https://assets.leetcode.com/uploads/2020/09/15/inorder\_1.jpg)

```
Input: root = [1,null,2,3]
Output: [1,3,2]
```

**Example 2:**

```
Input: root = []
Output: []
```

**Example 3:**

```
Input: root = [1]
Output: [1]
```

**Example 4:** ![](https://assets.leetcode.com/uploads/2020/09/15/inorder\_5.jpg)

```
Input: root = [1,2]
Output: [2,1]
```

**Example 5:** ![](https://assets.leetcode.com/uploads/2020/09/15/inorder\_4.jpg)

```
Input: root = [1,null,2]
Output: [1,2]
```

**Constraints:**

* The number of nodes in the tree is in the range `[0, 100]`.
* `-100 <= Node.val <= 100`

&#x20; **Follow up:** Recursive solution is trivial, could you do it iteratively?

## Solution

### Recursive Approach

```cpp
class Solution {
public:
    vector<int> result;
    void inorderUtil(TreeNode *root){
        if(!root)
            return;
        inorderUtil(root->left);
        result.push_back(root->val);
        inorderUtil(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        inorderUtil(root);
        return result;
    }
};
```

### Iterative Approach

```cpp
class Solution {
public:
   vector<int> inorderTraversal(TreeNode* root) {
       if(!root)
           return {};
       vector<int> result;
       stack<TreeNode*> s;
       TreeNode *curr = root;
       while(!s.empty() || curr != nullptr)
       {
           while(curr != nullptr)
           {
               s.push(curr);
               curr = curr->left;
           }
           curr = s.top();
           s.pop();
           result.push_back(curr->val);
           curr = curr->right;
       }
       return result;
   }
};
```
