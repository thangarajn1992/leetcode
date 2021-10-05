# Leetcode 117 Populating Next Right Pointers in Each Node II

## Problem Statement

[https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/](https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/)

Given a binary tree

```text
struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
```

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to `NULL`.

Initially, all next pointers are set to `NULL`.

**Example 1:** 

![](https://assets.leetcode.com/uploads/2019/02/15/117_sample.png)

```text
Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
```

**Example 2:**

```text
Input: root = []
Output: []
```

**Constraints:**

* The number of nodes in the tree is in the range `[0, 6000]`.
* `-100 <= Node.val <= 100`

**Follow-up:**

* You may only use constant extra space.
* The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.

## Solution

### O\(1\) Space Complexity

```cpp
class Solution {
public:
    
    Node* connect(Node* root) {
        Node* head = root;
        
        while(head != nullptr)
        {
            Node *dummy = new Node();
            Node *temp = dummy;
            
            // To take care of one level
            while(head != nullptr)
            {
                if(head->left != nullptr)
                {
                    temp->next = head->left;
                    temp = temp->next;
                }
                if(head->right != nullptr)
                {
                    temp->next = head->right;
                    temp = temp->next;
                }
                head = head->next;
            }
            
            // Once we complete this level, we will start next level
            head = dummy->next;
        }
        return root;
    }
};
```

### BFS or Level Order Traversal Approach

O\(N\) Time and Space Complexity

```cpp
class Solution {
public:
    /* BFS or Level Order Traversal Approach */
    /* O(N) Time and Space Complexity */
    Node* connect(Node* root) {
        if(root == nullptr)
            return root;
        
        queue<Node*> q;
        q.push(root);
        
        while(q.empty() == false)
        {
            int size = q.size();
            Node* dummy = new Node();
            for(int index = size-1; index >= 0; index--)
            {
                dummy->next = q.front(); q.pop();
                dummy = dummy->next;
                
                if(dummy->left != nullptr)
                    q.push(dummy->left);
                
                if(dummy->right != nullptr)
                    q.push(dummy->right);
            }
        }
        return root;
    }      
};
```

