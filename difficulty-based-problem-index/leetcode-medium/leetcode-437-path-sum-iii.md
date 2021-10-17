# Leetcode 437 Path Sum III

## Problem Statement

[https://leetcode.com/problems/path-sum-iii/](https://leetcode.com/problems/path-sum-iii/)

Given the `root` of a binary tree and an integer `targetSum`, return _the number of paths where the sum of the values along the path equals_ `targetSum`.

The path does not need to start or end at the root or a leaf, but it must go downwards (i.e., traveling only from parent nodes to child nodes).

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/04/09/pathsum3-1-tree.jpg)

```
Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
Output: 3
Explanation: The paths that sum to 8 are shown.
```

**Example 2:**

```
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: 3
```

**Constraints:**

* The number of nodes in the tree is in the range `[0, 1000]`.
* `-10^9 <= Node.val <= 10^9`
* `-1000 <= targetSum <= 1000`

## Solution

```cpp
class Solution {
public:
    // Returns No of paths having targetSum that begins from this node or from its children
    int pathSum(TreeNode* root, int targetSum) {
        if(root == nullptr) 
            return 0;
        return sumUp(root, 0, targetSum) + 
               pathSum(root->left, targetSum) + 
               pathSum(root->right, targetSum);
    }
private:
    
    // Returns No of paths having targetSum that begins from this node
    int sumUp(TreeNode* root, int pre, int& sum){
        if(root == nullptr) 
            return 0;
        int current = pre + root->val;
        return (current == sum) + sumUp(root->left, current, sum) + sumUp(root->right, current, sum);
    }
};
```
