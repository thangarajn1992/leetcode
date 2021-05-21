# Leetcode 145 Binary Tree Postorder Traversal

## Problem Statement

[https://leetcode.com/problems/binary-tree-postorder-traversal/](https://leetcode.com/problems/binary-tree-postorder-traversal/)

Given the `root` of a binary tree, return _the postorder traversal of its nodes' values_.

**Example 1:** ![](https://assets.leetcode.com/uploads/2020/08/28/pre1.jpg)

```text
Input: root = [1,null,2,3]
Output: [3,2,1]
```

**Example 2:**

```text
Input: root = []
Output: []
```

**Example 3:**

```text
Input: root = [1]
Output: [1]
```

**Example 4:** ![](https://assets.leetcode.com/uploads/2020/08/28/pre3.jpg)

```text
Input: root = [1,2]
Output: [2,1]
```

**Example 5:** ![](https://assets.leetcode.com/uploads/2020/08/28/pre2.jpg)

```text
Input: root = [1,null,2]
Output: [2,1]
```

**Constraints:**

* The number of the nodes in the tree is in the range `[0, 100]`.
* `-100 <= Node.val <= 100`

  **Follow up:** Recursive solution is trivial, could you do it iteratively?

## Solution

### Recursive Approach

```cpp
class Solution {
public:
    vector<int> result;
    void postorderUtil(TreeNode* root)
    {
        if(!root)
            return;
        postorderUtil(root->left);
        postorderUtil(root->right);
        result.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        postorderUtil(root);
        return result;
    }
};
```

### Iterative Approach

```cpp
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)
            return {};
        vector<int> result;
        stack<TreeNode *> s;
        unordered_map<TreeNode *, int> m;
        s.push(root);
        while(!s.empty())
        {
            TreeNode *curr = s.top();
            s.pop();
            while(curr)
            {
                if(!m[curr])
                {
                    m[curr] = 1;
                    if(curr->left == nullptr)
                    {
                        if(curr->right == nullptr)
                            result.push_back(curr->val);
                        else
                            s.push(curr);
                        
                        curr = curr->right;
                    }
                    else
                    {
                        s.push(curr);
                        curr = curr->left;
                    }
                }
                else
                {
                    if(curr->right == NULL || m[curr->right])
                    {
                        result.push_back(curr->val);
                        break;
                    }
                    else
                    {
                        s.push(curr);
                        curr = curr->right;
                    }
                }
            }   
        }
        return result;
    }
```

