# Leetcode 144 Binary Tree Preorder Traversal

## Problem Statement

[https://leetcode.com/problems/binary-tree-preorder-traversal/](https://leetcode.com/problems/binary-tree-preorder-traversal/)

Given the `root` of a binary tree, return _the preorder traversal of its nodes' values_.

**Example 1:** ![](https://assets.leetcode.com/uploads/2020/09/15/inorder_1.jpg)

```text
Input: root = [1,null,2,3]
Output: [1,2,3]
```

**Example 2:**

```text
Input: root = []
Output: []
```

**Example 3:**

```text
Input: root = [1]
Output: [1]
```

**Example 4:** ![](https://assets.leetcode.com/uploads/2020/09/15/inorder_5.jpg)

```text
Input: root = [1,2]
Output: [1,2]
```

**Example 5:** ![](https://assets.leetcode.com/uploads/2020/09/15/inorder_4.jpg)

```text
Input: root = [1,null,2]
Output: [1,2]
```

**Constraints:**

* The number of nodes in the tree is in the range `[0, 100]`.
* `-100 <= Node.val <= 100`

**Follow up:** Recursive solution is trivial, could you do it iteratively?

## Solution

### Recursive Solution

```cpp
class Solution {
public:
    vector<int> result;
    void preorderUtil(TreeNode *root)
    {
        if(!root)
            return;
        result.push_back(root->val);
        preorderUtil(root->left);
        preorderUtil(root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        preorderUtil(root);
        return result;
    }
};
```

### Iterative Solution

```cpp
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root)
            return {};
        vector<int> result;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode* temp = s.top();
            s.pop();
            result.push_back(temp->val);
            if(temp->right)
                s.push(temp->right);
            if(temp->left)
                s.push(temp->left);        
        }
        return result;
    }
};
```

