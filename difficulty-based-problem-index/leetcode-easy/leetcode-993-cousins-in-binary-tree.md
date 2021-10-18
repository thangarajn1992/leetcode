# Leetcode 993 Cousins in Binary Tree

## Problem Statement

[https://leetcode.com/problems/cousins-in-binary-tree/](https://leetcode.com/problems/cousins-in-binary-tree/)

Given the `root` of a binary tree with unique values and the values of two different nodes of the tree `x` and `y`, return `true` _if the nodes corresponding to the values _`x`_ and _`y`_ in the tree are **cousins**, or _`false`_ otherwise._

Two nodes of a binary tree are **cousins** if they have the same depth with different parents.

Note that in a binary tree, the root node is at the depth `0`, and children of each depth `k` node are at the depth `k + 1`.

 

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/02/12/q1248-01.png)

```
Input: root = [1,2,3,4], x = 4, y = 3
Output: false
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2019/02/12/q1248-02.png)

```
Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
```

**Example 3:**

![](https://assets.leetcode.com/uploads/2019/02/13/q1248-03.png)

```
Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
```

 

**Constraints:**

* The number of nodes in the tree is in the range `[2, 100]`.
* `1 <= Node.val <= 100`
* Each node has a **unique** value.
* `x != y`
* `x` and `y` are exist in the tree.

## Solution

```cpp
/* Breadth-First Search / Level Order Traversal */
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        int xDepth = -1, yDepth = -1;
        int xParent = 0, yParent = 0;
        
        // only one node can have depth 0 (root)
        // i.e no cousins for root node.
        if(root->val == x || root->val == y)
            return false;
        
        queue<TreeNode*> q;
        q.push(root);
        int currentDepth = 0;
        while(q.empty() == false)
        {
            currentDepth++;
            for(int index = q.size()-1; index >= 0; index--)
            {
                TreeNode* currentNode = q.front(); q.pop();
                
                if(currentNode->left)
                {
                    if(currentNode->left->val == x)
                    {
                        xDepth = currentDepth;
                        xParent = currentNode->val;
                    }
                    else if(currentNode->left->val == y)
                    {
                        yDepth = currentDepth;
                        yParent = currentNode->val;
                    }
                    q.push(currentNode->left);
                }
                
                if(currentNode->right)
                {
                    if(currentNode->right->val == x)
                    {
                        xDepth = currentDepth;
                        xParent = currentNode->val;
                    }
                    else if(currentNode->right->val == y)
                    {
                        yDepth = currentDepth;
                        yParent = currentNode->val;
                    }
                    q.push(currentNode->right);
                }
            }
            
            //Check whether both X and Y are present in this depth with different parents
            if(xDepth != -1 && xDepth == yDepth && 
               xParent != 0 && yParent != 0 && xParent != yParent)
            {
                // x and y are cousins
                return true;
            }
            if((xDepth != -1 && yDepth == -1) ||
               (yDepth != -1 && xDepth == -1))
            {
                // only one of x or y present in this depth.
                return false;
            }
            if(xDepth != -1 && yDepth != -1 && xParent == yParent)
            {
                // x and y are siblings
                return false;
            }
        }
        return false;
    }
};
```
