# Leetcode 198 House Robber

## Problem Statement

[https://leetcode.com/problems/house-robber/](https://leetcode.com/problems/house-robber/)

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and **it will automatically contact the police if two adjacent houses were broken into on the same night**.

Given an integer array `nums` representing the amount of money of each house, return _the maximum amount of money you can rob tonight **without alerting the police**_.

**Example 1:**

```text
Input: nums = [1,2,3,1]
Output: 4
Explanation: 
Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
```

**Example 2:**

```text
Input: nums = [2,7,9,3,1]
Output: 12
Explanation: 
Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.
```

**Constraints:**

* `1 <= nums.length <= 100`
* `0 <= nums[i] <= 40`

## Solution 

### Iterative Approach:

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        int incl = 0, excl = 0;
        for(int i = 0; i < size; i++)
        {
            int res = max(excl + nums[i], incl);
            excl = incl;
            incl = res;
        }
        return max(incl, excl);
    }
};
```

### Dynamic Programming Approach:

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> max_rob(nums.size(), 0);
        
        max_rob[0] = nums[0];
        max_rob[1] = max(nums[1], max_rob[0]);
        
        for(int i = 2; i < nums.size(); i++){
            max_rob[i] = max(max_rob[i-2] + nums[i], max_rob[i-1]);
        }
        
        return max_rob[nums.size()-1];
    }
};
```

