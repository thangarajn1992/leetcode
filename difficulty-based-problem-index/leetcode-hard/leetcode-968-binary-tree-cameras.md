# Leetcode 968 Binary Tree Cameras

## Problem Statement

Given a binary tree, we install cameras on the nodes of the tree. 

Each camera at a node can monitor **its parent, itself, and its immediate children**.

Calculate the minimum number of cameras needed to monitor all nodes of the tree.

**Example 1:** ![](https://assets.leetcode.com/uploads/2018/12/29/bst_cameras_01.png)

```text
Input: [0,0,null,0,0]
Output: 1
Explanation: 
One camera is enough to monitor all nodes if placed as shown.
```

**Example 2:** ![](https://assets.leetcode.com/uploads/2018/12/29/bst_cameras_02.png)

```text
Input: [0,0,null,0,null,0,null,null,0]
Output: 2
Explanation: 
At least two cameras are needed to monitor all nodes of the tree. 
The above image shows one of the valid configurations of camera placement.
```

  
 **Note:**

1. The number of nodes in the given tree will be in the range `[1, 1000]`.
2. **Every** node has value 0.

## Solution

```cpp
class Solution {
public:
    int cameras = 0;
    
    /* Return Value:
       0 - If camera is installed here.
       1 - If camera is with one of the child, so this node is covered
      -1 - If Node is not covered.
     */
    int helper(TreeNode* root)
    {
        if(root == NULL)
            return 1;
        int leftc = helper(root->left);
        int rightc = helper(root->right);
        if(leftc == -1 or rightc == -1)
        {
            cameras++;
            return 0;
        }
        if(leftc == 0 or rightc == 0)
            return 1;
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        if(helper(root) == -1)
            cameras++;
        return cameras;
    }
};
```

