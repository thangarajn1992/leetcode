# Leetcode 45 Jump Game II

## Problem Statement

[https://leetcode.com/problems/jump-game-ii/](https://leetcode.com/problems/jump-game-ii/)

Given an array of non-negative integers `nums`, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

You can assume that you can always reach the last index.

**Example 1:**

```text
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: 
The minimum number of jumps to reach the last index is 2. 
Jump 1 step from index 0 to 1, then 3 steps to the last index.
```

**Example 2:**

```text
Input: nums = [2,3,0,1,4]
Output: 2
```

**Constraints:**

* `1 <= nums.length <= 1000`
* `0 <= nums[i] <= 10^5`

## Solution

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> min_count(n,INT_MAX);
        min_count[n-1] = 0;
        for(int i = n - 2; i >= 0; i--)
        {
           if(!nums[i])
               continue;
           if(i + nums[i] >= n-1)
                min_count[i] = 1;
            else
                for(int j = i+1; j <= i+nums[i]; j++)
                    if(min_count[j] != INT_MAX)
                        min_count[i] = min(min_count[i], 1 + min_count[j]);
        }
        return min_count[0];
    }
};
```

