# Leetcode 160 Intersection of Two Linked Lists

## Problem Statement

[https://leetcode.com/problems/intersection-of-two-linked-lists/](https://leetcode.com/problems/intersection-of-two-linked-lists/)

Given the heads of two singly linked-lists `headA` and `headB`, return _the node at which the two lists intersect_. If the two linked lists have no intersection at all, return `null`.

For example, the following two linked lists begin to intersect at node `c1`: ![](https://assets.leetcode.com/uploads/2021/03/05/160\_statement.png)

It is **guaranteed** that there are no cycles anywhere in the entire linked structure.

**Note** that the linked lists must **retain their original structure** after the function returns.

**Example 1:** ![](https://assets.leetcode.com/uploads/2021/03/05/160\_example\_1\_1.png)

```
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
```

**Example 2:** ![](https://assets.leetcode.com/uploads/2021/03/05/160\_example\_2.png)

```
Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Intersected at '2'
Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.
```

**Example 3:** ![](https://assets.leetcode.com/uploads/2021/03/05/160\_example\_3.png)

```
Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: No intersection
Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
Explanation: The two lists do not intersect, so return null.
```

**Constraints:**

* The number of nodes of `listA` is in the `m`.
* The number of nodes of `listB` is in the `n`.
* `0 <= m, n <= 3 * 10^4`
* `1 <= Node.val <= 10^5`
* `0 <= skipA <= m`
* `0 <= skipB <= n`
* `intersectVal` is `0` if `listA` and `listB` do not intersect.
* `intersectVal == listA[skipA + 1] == listB[skipB + 1]` if `listA` and `listB` intersect.

&#x20; **Follow up:** Could you write a solution that runs in `O(n)` time and use only `O(1)` memory?

## Solution

### Two pointer Approach

```cpp
class Solution {
public:
    // curA starts from headA and once it reaches its end,then moves to headB
    // curB starts from headB and once it reaches its end,then moves to headA
    // If there is an intersection, they will meet at that node otherwise
    // they both endup traversing both lists once and meet at end (null).
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA = headA, *curB = headB;
        while(curA != curB)
        {
            curA = curA ? curA->next : headB;
            curB = curB ? curB->next : headA;
        }
        return curA;
    }
};
```

### Calculate length of lists approach

```cpp
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp;
        int cnt1 = 0, cnt2 = 0;
        for(temp = headA; temp; temp = temp->next)
            cnt1++;
        for(temp = headB; temp; temp = temp->next)
            cnt2++;
            
        int diff = abs(cnt1 - cnt2);
        if(cnt1 > cnt2)
            while(diff--)
                headA = headA->next;
        else
            while(diff--)
                headB = headB->next;
                
        while(headA && headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};  
```
