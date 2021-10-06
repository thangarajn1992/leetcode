# Leetcode 213 House Robber II

## Problem Statement

[https://leetcode.com/problems/house-robber-ii/](https://leetcode.com/problems/house-robber-ii/)

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are **arranged in a circle.** That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and **it will automatically contact the police if two adjacent houses were broken into on the same night**.

Given an integer array `nums` representing the amount of money of each house, return _the maximum amount of money you can rob tonight **without alerting the police**_.

**Example 1:**

```text
Input: nums = [2,3,2]
Output: 3
Explanation: 
You cannot rob house 1 (money = 2) and then rob house 3 (money = 2), because they are 
adjacent houses.
```

**Example 2:**

```text
Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.
```

**Example 3:**

```text
Input: nums = [1,2,3]
Output: 3
```

**Constraints:**

* `1 <= nums.length <= 100`
* `0 <= nums[i] <= 1000`

## Solution

```cpp
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        int incl = 0, excl = 0;
        int answer = nums[0];
        
        // calc max without last house
        for(int i = 0; i < size - 1; i++)
        {
            int res = max(excl + nums[i], incl);
            excl = incl;
            incl = res;
        }
        answer = max(answer, max(incl, excl));
        
        // calc max without first house
        incl = 0, excl = 0;
        for(int i = 1; i < size; i++)
        {
            int res = max(excl + nums[i], incl);
            excl = incl;
            incl = res;
        }
        answer = max(answer, max(incl, excl));
        return answer;
    }
};
```

