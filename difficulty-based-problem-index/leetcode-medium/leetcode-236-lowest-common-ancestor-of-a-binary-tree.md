# Leetcode 236 Lowest Common Ancestor of a Binary Tree

## Problem Statement

[https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/)

Given a binary tree, find the lowest common ancestor \(LCA\) of two given nodes in the tree.

According to the [definition of LCA on Wikipedia](https://en.wikipedia.org/wiki/Lowest_common_ancestor): “The lowest common ancestor is defined between two nodes `p` and `q` as the lowest node in `T` that has both `p` and `q` as descendants \(where we allow **a node to be a descendant of itself**\).”

**Example 1:** ![](https://assets.leetcode.com/uploads/2018/12/14/binarytree.png)

```text
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: 
The LCA of nodes 5 and 1 is 3.
```

**Example 2:** ![](https://assets.leetcode.com/uploads/2018/12/14/binarytree.png)

```text
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: 
The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to 
the LCA definition.
```

**Example 3:**

```text
Input: root = [1,2], p = 1, q = 2
Output: 1
```

**Constraints:**

* The number of nodes in the tree is in the range `[2, 10^5]`.
* `-10^9 <= Node.val <= 10^9`
* All `Node.val` are **unique**.
* `p != q`
* `p` and `q` will exist in the tree.

## Solution

### My Approach

```cpp
class Solution {
public:
    vector<TreeNode*> p_path;
    vector<TreeNode*> q_path;
    bool p_found = false;
    bool q_found = false;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        find_p_q(root, p, q);
        int i;
        
        int path_size = min(p_path.size(), q_path.size());
        
        // Find the node at which their path differs
        for(i = 0; i < path_size && p_path[i] == q_path[i]; i++);

        return p_path[i-1];
    }
    void find_p_q(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        bool old_p_found = p_found, old_q_found = q_found;

        if(!p_found)  p_path.push_back(root);
        
        if(!q_found)  q_path.push_back(root);
        
        if(root == p) p_found = true;
    
        if(root == q) q_found = true;
        
        if(p_found && q_found) return;

        if(root->left)  find_p_q(root->left, p, q);
        
        if(p_found && q_found) return;
            
        // Search right sub-tree if still p and q are not found
        if(root->right)  find_p_q(root->right, p, q);
            
        // In this path P doesnt exists, remove this node from path to P
        if(old_p_found == false && p_found == false) p_path.pop_back();
            
        // In this path Q doesnt exists, remove this node from path to Q
        if(old_q_found == false && q_found == false) q_path.pop_back();       
    }
};
```

