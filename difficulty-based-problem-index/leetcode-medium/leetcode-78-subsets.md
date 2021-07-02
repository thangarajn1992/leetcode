# Leetcode 78 Subsets

## Problem Statement

[https://leetcode.com/problems/subsets/](https://leetcode.com/problems/subsets/)

Given an integer array `nums` of **unique** elements, return _all possible subsets \(the power set\)_.

The solution set **must not** contain duplicate subsets. Return the solution in **any order**.

**Example 1:**

```text
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
```

**Example 2:**

```text
Input: nums = [0]
Output: [[],[0]]
```

**Constraints:**

* `1 <= nums.length <= 10`
* `-10 <= nums[i] <= 10`
* All the numbers of `nums` are **unique**.

## Solution

### Recursive - Backtracking Approach

```cpp
class Solution {
public:
    void subsets_recur(vector<int>&nums, int index, vector<int> subset, 
                       vector<vector<int>> &result)
    {
        if(nums.size() == index)
        {
            result.push_back(subset);
            return;
        }
        
        subsets_recur(nums, index+1, subset, result);
        subset.push_back(nums[index]);
        subsets_recur(nums, index+1, subset, result);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        subsets_recur(nums, 0, subset , result);
        return result;
    }
};
```

### Iterative - Bit Manipulation Approach

```cpp
class Solution {
public:
/* Iterative Approach - Using bit property */
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector <vector<int>> ans;

        for(int i = 0; i < (1<<n); i++) {            
            vector <int> temp;
            for(int j = 0; j < n; j++) {
                if(i & 1<<j) {
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans; 
    }
};
```

