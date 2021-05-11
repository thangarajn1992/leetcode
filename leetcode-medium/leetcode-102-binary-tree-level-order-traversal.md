# Leetcode 102 Binary Tree Level Order Traversal

## Problem Statement

[https://leetcode.com/problems/binary-tree-level-order-traversal/](https://leetcode.com/problems/binary-tree-level-order-traversal/)

Given the `root` of a binary tree, return _the level order traversal of its nodes' values_. \(i.e., from left to right, level by level\).

**Example 1:** ![](https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg)

```text
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[9,20],[15,7]]
```

**Example 2:**

```text
Input: root = [1]
Output: [[1]]
```

**Example 3:**

```text
Input: root = []
Output: []
```

**Constraints:**

* The number of nodes in the tree is in the range `[0, 2000]`.
* `-1000 <= Node.val <= 1000`

## Solution

### Recursive Approach

```cpp
class Solution {
public:
    void levelOrderTraversal(TreeNode* root, vector<vector<int>>& result, int level)
    {
        if(!root)
            return;
        if(result.size() <= level){
            result.push_back({});
        }
        result[level].push_back(root->val);
        levelOrderTraversal(root->left, result, level+1);
        levelOrderTraversal(root->right, result, level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        levelOrderTraversal(root, result, 0);
        return result;
    }
};
```

### Iterative Approach

```cpp
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (not root) {
            return {};
        }
        
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        
        q.push(root);
        
        while  (!q.empty()) {
            ans.push_back({});
            
            for (int i = q.size(); i > 0; i--) {
                ans.back().push_back(q.front()->val);
                
                if (q.front()->left) {
                    q.push(q.front()->left);
                }
                
                if (q.front()->right) {
                    q.push(q.front()->right);
                }
                
                q.pop();
            }
        }
        
        return ans;
    }
};
```

