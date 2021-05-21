# Leetcode 107 Binary Tree Level Order Traversal II

## Problem Statement

[https://leetcode.com/problems/binary-tree-level-order-traversal-ii/](https://leetcode.com/problems/binary-tree-level-order-traversal-ii/)

Given the `root` of a binary tree, return _the bottom-up level order traversal of its nodes' values_. \(i.e., from left to right, level by level from leaf to root\).

**Example 1:** ![](https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg)

```text
Input: root = [3,9,20,null,null,15,7]
Output: [[15,7],[9,20],[3]]
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

### Iterative approach without reverse

```cpp
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (not root) {
            return {};
        }
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while  (!q.empty()) {
            vector<int> temp; 
            for (int i = q.size(); i > 0; i--) {
                temp.push_back(q.front()->val);
                
                if (q.front()->left) {
                    q.push(q.front()->left);
                }
                
                if (q.front()->right) {
                    q.push(q.front()->right);
                }
                
                q.pop();
            }
            ans.insert(ans.begin(), temp);
        }
        
        return ans;
    }
};
```

