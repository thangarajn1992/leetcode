# Leetcode 1302 Deepest Leaves Sum

## Problem Statement

[https://leetcode.com/problems/deepest-leaves-sum/](https://leetcode.com/problems/deepest-leaves-sum/)

Given the `root` of a binary tree, return _the sum of values of its deepest leaves_.

**Example 1:** ![](https://assets.leetcode.com/uploads/2019/07/31/1483_ex1.png)

```text
Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
Output: 15
```

**Example 2:**

```text
Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
Output: 19
```

**Constraints:**

* The number of nodes in the tree is in the range `[1, 10^4]`.
* `1 <= Node.val <= 100`

## Solution

```cpp
class Solution {
public:
    int sum = 0;
    int max_depth = 0;
    void deepestLeavesSumUtil(TreeNode* root, int depth)
    {
        if(!root)
            return;
        if(!root->left && !root->right)
        {
            if(depth == max_depth)
                sum += root->val;
            if(depth > max_depth)
            {
                max_depth = depth;
                sum = root->val;
            }
            return;
        }
        deepestLeavesSumUtil(root->left, depth + 1);
        deepestLeavesSumUtil(root->right, depth + 1);
    }
    int deepestLeavesSum(TreeNode* root) {
        deepestLeavesSumUtil(root, 0);
        return sum;
    }
};
```



