# Leetcode 103 Binary Tree Zigzag Level Order Traversal

## Problem Statement

[https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/](https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/)

Given the `root` of a binary tree, return _the zigzag level order traversal of its nodes' values_. \(i.e., from left to right, then right to left for the next level and alternate between\).

**Example 1:** ![](https://assets.leetcode.com/uploads/2021/02/19/tree1.jpg)

```text
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]
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
* `-100 <= Node.val <= 100`

## Solution

```cpp
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (not root) {
            return {};
        }
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()) {
            ans.push_back({});
            for (int i = q.size(); i > 0; i--) {
                if(level % 2)
                    ans[level].insert(ans[level].begin(),q.front()->val);
                else
                    ans[level].push_back(q.front()->val);
                
                if (q.front()->left) {
                    q.push(q.front()->left);
                }
                if (q.front()->right) {
                    q.push(q.front()->right);
                }
                q.pop();
            }
            level++;
        } 
        return ans;        
    }
};
```

