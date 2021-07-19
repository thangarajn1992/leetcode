# Leetcode 1046 Last Stone Weight

## Problem Statement

[https://leetcode.com/problems/last-stone-weight/](https://leetcode.com/problems/last-stone-weight/)

We have a collection of stones, each stone has a positive integer weight.

Each turn, we choose the two **heaviest** stones and smash them together.  Suppose the stones have weights `x` and `y` with `x <= y`.  The result of this smash is:

* If `x == y`, both stones are totally destroyed;
* If `x != y`, the stone of weight `x` is totally destroyed, and the stone of weight `y` has new weight `y-x`.

At the end, there is at most 1 stone left.  Return the weight of this stone \(or 0 if there are no stones left.\)

**Example 1:**

```text
Input: [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of 
last stone.
```

**Note:**

1. `1 <= stones.length <= 30`
2. `1 <= stones[i] <= 1000`

## Solution

### Priority Queue

```cpp
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int, vector<int>, less<int>> q;
        for(int stone : stones)
            q.push(stone);
        
        while(q.size() > 1)
        {
            int first = q.top(); q.pop();
            int second = q.top(); q.pop();
            
            if(first > second)
                q.push(first - second);
        }
        
        return q.size() ? q.top() : 0;
    }
};
```

### Repeated Sorting

```cpp
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while(stones.size() > 1)
        {
            sort(stones.begin(), stones.end());
            int first = stones[stones.size() - 1];
            int second = stones[stones.size() - 2];
            stones.pop_back();
            if(first > second)
                stones[stones.size() - 1] = first - second;
            else
                stones.pop_back();
        }
        return stones.size() ? stones[0] : 0;
    }
};
```

