# Leetcode 114 Flatten Binary Tree to Linked List

## Problem Statement

[https://leetcode.com/problems/flatten-binary-tree-to-linked-list/](https://leetcode.com/problems/flatten-binary-tree-to-linked-list/)

Given the `root` of a binary tree, flatten the tree into a "linked list":

* The "linked list" should use the same `TreeNode` class where the `right` child pointer points to the next node in the list and the `left` child pointer is always `null`.
* The "linked list" should be in the same order as a [**pre-order** **traversal**](https://en.wikipedia.org/wiki/Tree\_traversal#Pre-order,\_NLR) of the binary tree.

**Example 1:** ![](https://assets.leetcode.com/uploads/2021/01/14/flaten.jpg)

```
Input: root = [1,2,5,3,4,null,6]
Output: [1,null,2,null,3,null,4,null,5,null,6]
```

**Example 2:**

```
Input: root = []
Output: []
```

**Example 3:**

```
Input: root = [0]
Output: [0]
```

**Constraints:**

* The number of nodes in the tree is in the range `[0, 2000]`.
* `-100 <= Node.val <= 100`

&#x20; **Follow up:** Can you flatten the tree in-place (with `O(1)` extra space)?

## Solution

### Iterative or using deque

```cpp
class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == nullptr)
            return;
        stack<TreeNode*> NodeStack;
        TreeNode *prev = nullptr;
        NodeStack.push(root);
        while(!NodeStack.empty())
        {
            TreeNode* curr = NodeStack.top();
            NodeStack.pop();
            if(curr->right)
                NodeStack.push(curr->right);
            if(curr->left)
                NodeStack.push(curr->left);
            if(prev) prev->right = curr;
            prev = curr;
            curr->left = curr->right = nullptr;
        }
    }
};
```

### Recursive and memory-efficient

```cpp
class Solution {
public:
    TreeNode* flattenutil(TreeNode* root)
    {
        if(root == nullptr)
            return root;
        TreeNode* left = flattenutil(root->left);
        TreeNode* right = flattenutil(root->right);
        if(left)
        {
            left->right = root->right;
            root->right = root->left;
        }
        root->left = nullptr;
        return right? right : left? left : root;
    }
    void flatten(TreeNode* root) {
        flattenutil(root);
    }
};
```
