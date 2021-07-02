# Leetcode 46 Permutations

## Problem Statement

[https://leetcode.com/problems/permutations/](https://leetcode.com/problems/permutations/)

Given an array `nums` of distinct integers, return _all the possible permutations_. You can return the answer in **any order**.

**Example 1:**

```text
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
```

**Example 2:**

```text
Input: nums = [0,1]
Output: [[0,1],[1,0]]
```

**Example 3:**

```text
Input: nums = [1]
Output: [[1]]
```

**Constraints:**

* `1 <= nums.length <= 6`
* `-10 <= nums[i] <= 10`
* All the integers of `nums` are **unique**.

## Solution

```cpp
class Solution {
public:
    void permute_recur(vector<int>&nums, int index, vector<vector<int>> &result)
    {
        if(nums.size() == index)
        {
            result.push_back(nums);
            return;
        }
        for(int i = index; i < nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            permute_recur(nums, index+1, result);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permute_recur(nums, 0, result);
        return result;
    }
};
```

