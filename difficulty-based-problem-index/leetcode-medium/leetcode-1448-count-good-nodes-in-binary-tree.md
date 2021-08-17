# Leetcode 1448 Count Good Nodes in Binary Tree

## Problem Statement

[https://leetcode.com/problems/count-good-nodes-in-binary-tree/](https://leetcode.com/problems/count-good-nodes-in-binary-tree/)

Given a binary tree `root`, a node _X_ in the tree is named **good** if in the path from root to _X_ there are no nodes with a value _greater than_ X.

Return the number of **good** nodes in the binary tree.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/04/02/test_sample_1.png)

```text
Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2020/04/02/test_sample_2.png)

```text
Input: root = [3,3,null,4,2]
Output: 3
Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.
```

**Example 3:**

```text
Input: root = [1]
Output: 1
Explanation: Root is considered as good.
```

**Constraints:**

* The number of nodes in the binary tree is in the range `[1, 10^5]`.
* Each node's value is between `[-10^4, 10^4]`.

## Solution

```cpp
class Solution {
public:
    int count = 0;
    int goodNodes(TreeNode* root) {
        goodNodesUtil(root, INT_MIN);  
        return count;
    }
    
    void goodNodesUtil(TreeNode* root, int max_so_far)
    {
        if(root == nullptr)
            return;
        
        if(root->val >= max_so_far)
        {
            count++;
            max_so_far = root->val;
        }
        
        goodNodesUtil(root->left, max_so_far);
        goodNodesUtil(root->right, max_so_far);
    }
};
```

