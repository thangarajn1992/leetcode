# Leetcode 473 Matchsticks to Square

## Problem Statement

[https://leetcode.com/problems/matchsticks-to-square/](https://leetcode.com/problems/matchsticks-to-square/)

You are given an integer array `matchsticks` where `matchsticks[i]` is the length of the `ith` matchstick. You want to use **all the matchsticks** to make one square. You **should not break** any stick, but you can link them up, and each matchstick must be used **exactly one time**.

Return `true` if you can make this square and `false` otherwise.

**Example 1:** ![](https://assets.leetcode.com/uploads/2021/04/09/matchsticks1-grid.jpg)

```text
Input: matchsticks = [1,1,2,2,2]
Output: true
Explanation: 
You can form a square with length 2, one side of the square came two sticks with length 1.
```

**Example 2:**

```text
Input: matchsticks = [3,3,3,3,4]
Output: false
Explanation: 
You cannot find a way to form a square with all the matchsticks.
```

**Constraints:**

* `1 <= matchsticks.length <= 15`
* `0 <= matchsticks[i] <= 10^9`

## Solution

```cpp
class Solution {
public:
    int square_side;
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size() < 4)
            return false;
            
        // Sorting improves the time from 180ms to 4ms
        sort(matchsticks.begin(), matchsticks.end(), greater<>());
        int sum = 0;
        for(int i : matchsticks)
            sum += i;

        if(!sum || sum%4 != 0 || sum/4 < matchsticks[0])
            return false;
            
        square_side = sum/4;
        vector<int> side(4,0);
        return is_square(matchsticks, 0, side);
    }
    bool is_square(vector<int>& m, int index, vector<int>&side)
    {        
        if(index == m.size()) // If we reach here, then all sides are same.
            return true;
        
        for(int i = 0; i < 4; i++)
        {
            // If we are exceeding our required square_side, skip it
            if(side[i] + m[index] > square_side)
                continue;
            
            // if we have two sides of same length right now, dont need to do DFS
            // for both sides, they will yield same result
            int j = i;
            
            while(--j >= 0 && side[i] != side[j]);

            if(j != -1)
                continue;
            
            side[i] += m[index];
            if(is_square(m, index+1, side))
                return true;
            side[i] -= m[index];
        }
        return false;
    }
};
```

