# Leetcode 18 4Sum

## Problem Statement

[https://leetcode.com/problems/4sum/](https://leetcode.com/problems/4sum/)

Given an array `nums` of `n` integers, return _an array of all the **unique** quadruplets_ `[nums[a], nums[b], nums[c], nums[d]]` such that:

* `0 <= a, b, c, d < n`
* `a`, `b`, `c`, and `d` are **distinct**.
* `nums[a] + nums[b] + nums[c] + nums[d] == target`

You may return the answer in **any order**.

**Example 1:**

```text
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
```

**Example 2:**

```text
Input: nums = [2,2,2,2,2], target = 8
Output: [[2,2,2,2]]
```

**Constraints:**

* `1 <= nums.length <= 200`
* `-10^9 <= nums[i] <= 10^9`
* `-10^9 <= target <= 10^9`

## Solution

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return ksum(nums, target, 0, 4);
    }
    
    vector<vector<int>> ksum(vector<int>&nums, int target, int start, int k)
    {
        vector<vector<int>> res;
        if(start == nums.size() || nums[start] * k > target || nums.back()*k < target)
            return res;
        
        if(k == 2)
            return two_sum(nums, target, start);
        
        for(int i = start; i < nums.size(); i++)
            if(i == start || nums[i-1] != nums[i])    
                for(vector<int> &k_minus_1_sum : ksum(nums, target - nums[i], i+1, k-1))
                {
                    k_minus_1_sum.insert(k_minus_1_sum.begin(), nums[i]);
                    res.push_back(k_minus_1_sum);
                }
        return res;
    }
    
    vector<vector<int>> two_sum(vector<int>&nums, int target, int start)
    {
        vector<vector<int>> result;
        int left = start, right = nums.size() -1;
        while(left < right)
        {
            int sum = nums[left] + nums[right];
            if(sum < target)
                left++;
            else if (sum > target || (right < nums.size()-1 && nums[right] == nums[right+1]))
                right--;
            else
                result.push_back({nums[left++], nums[right--]});
        }
        return result;
    }
};
```

