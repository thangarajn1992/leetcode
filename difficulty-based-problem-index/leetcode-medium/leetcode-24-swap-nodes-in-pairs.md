# Leetcode 24 Swap Nodes in Pairs

[https://leetcode.com/problems/swap-nodes-in-pairs/](https://leetcode.com/problems/swap-nodes-in-pairs/)

Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

**Example 1:** ![](https://assets.leetcode.com/uploads/2020/10/03/swap\_ex1.jpg)

```
Input: head = [1,2,3,4]
Output: [2,1,4,3]
```

**Example 2:**

```
Input: head = []
Output: []
```

**Example 3:**

```
Input: head = [1]
Output: [1]
```

**Constraints:**

* The number of nodes in the list is in the range `[0, 100]`.
* `0 <= Node.val <= 100`

## Solution

### Recursive Approach

```cpp
class Solution {
public:
    /* Recursive Solution */
     ListNode* swapPairs(ListNode* head) {
         if(head == nullptr || head->next == nullptr)
             return head;
         
         ListNode *nextPair = head->next->next;
         ListNode *newHead = head->next;
         newHead->next = head;
         head->next = swapPairs(nextPair);
         return newHead;
     }
 };
```

### Iterative Approach

```cpp
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy, *curr = head;
        while(curr && curr->next)
        {
            prev->next = curr->next;
            curr->next = curr->next->next;
            prev->next->next = curr;
            prev = curr;
            curr = curr->next; 
        }
        return dummy->next;
    }
};
```
