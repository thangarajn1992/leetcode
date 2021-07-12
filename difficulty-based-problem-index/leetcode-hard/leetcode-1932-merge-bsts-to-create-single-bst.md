# Leetcode 1932 Merge BSTs to Create Single BST

## Problem Statement

[https://leetcode.com/problems/merge-bsts-to-create-single-bst/](https://leetcode.com/problems/merge-bsts-to-create-single-bst/)

You are given `n` **BST \(binary search tree\) root nodes** for `n` separate BSTs stored in an array `trees` \(**0-indexed**\). Each BST in `trees` has **at most 3 nodes**, and no two roots have the same value. In one operation, you can:

* Select two **distinct** indices `i` and `j` such that the value stored at one of the **leaves** of `trees[i]` is equal to the **root value** of `trees[j]`.
* Replace the leaf node in `trees[i]` with `trees[j]`.
* Remove `trees[j]` from `trees`.

Return _the **root** of the resulting BST if it is possible to form a valid BST after performing_ `n - 1` _operations, or_ `null` if it is impossible to create a valid BST.

A BST \(binary search tree\) is a binary tree where each node satisfies the following property:

* Every node in the node's left subtree has a value **strictly less** than the node's value.
* Every node in the node's right subtree has a value **strictly greater** than the node's value.

A leaf is a node that has no children.

**Example 1:** ![](https://assets.leetcode.com/uploads/2021/06/08/d1.png)

```text
Input: trees = [[2,1],[3,2,5],[5,4]]
Output: [3,2,5,1,null,4]
Explanation:
In the first operation, pick i=1 and j=0, and merge trees[0] into trees[1].
Delete trees[0], so trees = [[3,2,5,1],[5,4]].

In the second operation, pick i=0 and j=1, and merge trees[1] into trees[0].
Delete trees[1], so trees = [[3,2,5,1,null,4]].

The resulting tree, shown above, is a valid BST, so return its root.
```

**Example 2:** ![](https://assets.leetcode.com/uploads/2021/06/08/d2.png)

```text
Input: trees = [[5,3,8],[3,2,6]]
Output: []
Explanation:
Pick i=0 and j=1 and merge trees[1] into trees[0].
Delete trees[1], so trees = [[5,3,8,2,6]].

The resulting tree is shown above. This is the only valid operation that can be performed,
but the resulting tree is not a valid BST, so return null.
```

**Example 3:** ![](https://assets.leetcode.com/uploads/2021/06/08/d3.png)

```text
Input: trees = [[5,4],[3]]
Output: []
Explanation: It is impossible to perform any operations.
```

**Example 4:** ![](https://assets.leetcode.com/uploads/2021/06/08/d4.png)

```text
Input: trees = [[2,1,3]]
Output: [2,1,3]
Explanation: 
There is only one tree, and it is already a valid BST, so return its root.
```

**Constraints:**

* `n == trees.length`
* `1 <= n <= 5 * 10^4`
* The number of nodes in each tree is in the range `[1, 3]`.
* No two roots of `trees` have the same value.
* All the trees in the input are **valid BSTs**.
* `1 <= TreeNode.val <= 5 * 10^4`.

## Solution

```cpp
class Solution {
public:
    bool traverse(TreeNode* r, unordered_map<int, TreeNode*> &m, int min_left, int max_right) 
    {
        if (r == nullptr) 
            return true;
        if (r->val <= min_left || r->val >= max_right)
            return false;
            
        // For leaf node, find the root node with same value and
        // make its children as this leaf node's children
        // and remove that root from the root map
        if (r->left == r->right) {
            auto it = m.find(r->val);
            if (it != end(m) && r != it->second) {
                r->left = it->second->left;
                r->right = it->second->right;
                m.erase(it);
            }
        }
        return traverse(r->left, m, min_left, r->val) && 
               traverse(r->right, m, r->val, max_right);
    }    
    
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        unordered_map<int, TreeNode*> m; // Map with just Root nodes
        unordered_map<int, int> cnt; // No. of nodes with this value
        
        //Updating roots map and count map
        for (auto &t : trees) {
            m[t->val] = t;
            cnt[t->val]++;
            if(t->left) cnt[t->left->val]++;
            if(t->right) cnt[t->right->val]++;
        }
        
        // Final root would have occured only once and only one root should have occured only one.
        for (auto &t : trees)
            if (cnt[t->val] == 1)
                return traverse(t, m, INT_MIN, INT_MAX) && m.size() == 1 ? t : nullptr;
            return nullptr;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
```

