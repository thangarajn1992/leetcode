# Leetcode 665 Non-decreasing Array

## Problem Statement

[https://leetcode.com/problems/non-decreasing-array/](https://leetcode.com/problems/non-decreasing-array/)

Given an array `nums` with `n` integers, your task is to check if it could become non-decreasing by modifying **at most one element**.

We define an array as non-decreasing if `nums[i] <= nums[i + 1]` holds for every `i` \(**0-based**\) such that \(`0 <= i <= n - 2`\).

**Example 1:**

```text
Input: nums = [4,2,3]
Output: true
Explanation: 
You could modify the first 4 to 1 to get a non-decreasing array.
```

**Example 2:**

```text
Input: nums = [4,2,1]
Output: false
Explanation: 
You can't get a non-decreasing array by modify at most one element.
```

**Constraints:**

* `n == nums.length`
* `1 <= n <= 10^4`
* `-10^5 <= nums[i] <= 10^5`

## Solution

### Easier Solution

```cpp
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
         int n = nums.size();
        int prev = nums[0];
        int allowance = 1;
        for(int i = 1; i < n; i++)
        {
            if(nums[i] >= prev)
                prev = nums[i];
            else
            {
                if(allowance==0)
                    return false;
                allowance--;
                if(i-2 < 0 || nums[i] >= nums[i-2])
                    prev = nums[i];
            }
        }
        return true;
    }
};
```

### Complex Solution

```cpp
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int change = 0;
        for(int i = 1; i < nums.size(); i++)
            if(nums[i] < nums[i-1])
                if(change++ || 
                   (i > 1 && i < nums.size()-1 && nums[i-2] > nums[i] && nums[i+1] < nums[i-1]))
                    return 0;
        return 1;
    }
};
```

