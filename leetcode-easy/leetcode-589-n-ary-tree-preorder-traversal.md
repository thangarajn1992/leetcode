# Leetcode 589  N-ary Tree Preorder Traversal

## Problem Statement

[https://leetcode.com/problems/n-ary-tree-preorder-traversal/](https://leetcode.com/problems/n-ary-tree-preorder-traversal/)

Given the `root` of an n-ary tree, return _the preorder traversal of its nodes' values_.

Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value \(See examples\)

**Example 1:**

![](https://assets.leetcode.com/uploads/2018/10/12/narytreeexample.png)

```text
Input: root = [1,null,3,2,4,null,5,6]
Output: [1,3,5,6,2,4]
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2019/11/08/sample_4_964.png)

```text
Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]
```

**Constraints:**

* The number of nodes in the tree is in the range `[0, 10^4]`.
* `0 <= Node.val <= 10^4`
* The height of the n-ary tree is less than or equal to `1000`.

**Follow up:** Recursive solution is trivial, could you do it iteratively?

## Solution

### Recursive Solution

```cpp
class Solution {
public:
    vector<int> result;
    void preorderutil(Node * root) {
        result.push_back(root->val);
        int size = root->children.size();
        for(int i = 0; i < size; i++)
            preorderutil(root->children[i]);
    }
    vector<int> preorder(Node* root) {  
        if(!root)
            return result;
        preorderutil(root);
        return result;

    }
};
```

### Iterative Solution

```cpp
class Solution {
public:
    vector<int> preorder(Node* root) {  
         vector<int> result;
         stack<Node*> s;
         if(!root)
             return result;
         s.push(root);
         while(!s.empty())
         {
             Node *temp = s.top();
             s.pop();
             result.push_back(temp->val);
             for(int i = temp->children.size() - 1; i >= 0; i--)
                 s.push(temp->children[i]);
         }
         return result;
    }
};
```

