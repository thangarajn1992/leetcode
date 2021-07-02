# Leetcode 377 Combination Sum IV

## Problem Statement

[https://leetcode.com/problems/combination-sum-iv/](https://leetcode.com/problems/combination-sum-iv/)

Given an array of **distinct** integers `nums` and a target integer `target`, return _the number of possible combinations that add up to_ `target`.

The answer is **guaranteed** to fit in a **32-bit** integer.

**Example 1:**

```text
Input: nums = [1,2,3], target = 4
Output: 7
Explanation:
The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.
```

**Example 2:**

```text
Input: nums = [9], target = 3
Output: 0
```

**Constraints:**

* `1 <= nums.length <= 200`
* `1 <= nums[i] <= 1000`
* All the elements of `nums` are **unique**.
* `1 <= target <= 1000`

## Solution

```cpp
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target+1, 0);
        dp[0] = 1;
        for (int i = 1; i <= target; i++)
            for (int num : nums)
                if (num <= i) dp[i] += dp[i-num];
        return dp[target];
    }
};
```

