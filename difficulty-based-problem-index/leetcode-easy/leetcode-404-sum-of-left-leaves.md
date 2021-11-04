# Leetcode 404 Sum of Left Leaves

## Problem Statement

[https://leetcode.com/problems/sum-of-left-leaves/](https://leetcode.com/problems/sum-of-left-leaves/)

Given the `root` of a binary tree, return the sum of all left leaves.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/04/08/leftsum-tree.jpg)

```
Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: 
There are two left leaves in the binary tree, with values 9 and 15 respectively.
```

**Example 2:**

```
Input: root = [1]
Output: 0
```

**Constraints:**

* The number of nodes in the tree is in the range `[1, 1000]`.
* `-1000 <= Node.val <= 1000`

## Solution

### Queue Based Breadth First Search

```cpp
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int leftLeavesSum = 0;
        queue<pair<TreeNode*, bool>> q;
        q.push({root, false});
        
        while(q.empty() == false)
        {
            for(int i = q.size()-1; i >= 0; i--)
            {
                TreeNode *curr = q.front().first;
                
                // Is left leaf
                if(q.front().second == true && curr->left == nullptr && curr->right == nullptr)
                    leftLeavesSum += curr->val;
                
                if(curr->left != nullptr)
                    q.push({curr->left, true});
                
                if(curr->right != nullptr)
                    q.push({curr->right, false});
                
                q.pop();
            }
        }
        return leftLeavesSum;
    }
};
```
