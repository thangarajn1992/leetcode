# Leetcode 101 Symmetric Tree

## Problem Statement

[https://leetcode.com/problems/symmetric-tree/](https://leetcode.com/problems/symmetric-tree/)

Given the `root` of a binary tree, _check whether it is a mirror of itself_ \(i.e., symmetric around its center\).

**Example 1:** ![](https://assets.leetcode.com/uploads/2021/02/19/symtree1.jpg)

```text
Input: root = [1,2,2,3,4,4,3]
Output: true
```

**Example 2:** ![](https://assets.leetcode.com/uploads/2021/02/19/symtree2.jpg)

```text
Input: root = [1,2,2,null,3,null,3]
Output: false
```

**Constraints:**

* The number of nodes in the tree is in the range `[1, 1000]`.
* `-100 <= Node.val <= 100`

  **Follow up:** Could you solve it both recursively and iteratively?

## Solution

### Recursive Approach

```cpp
class Solution {
public:
    bool isSymmetricUtil(TreeNode* root1, TreeNode *root2)
    {
        if(root1 == nullptr && root2 == nullptr)
            return true;
        if(root1 == nullptr || root2 == nullptr)
            return false;
        if(root1->val != root2->val)
            return false;
        return isSymmetricUtil(root1->left, root2->right) && 
               isSymmetricUtil(root1->right, root2->left); 
    }
    
    bool isSymmetric(TreeNode* root) {
        return isSymmetricUtil(root->left, root->right);
    }
};
```

