# Leetcode 90 Subsets II

## Problem Statement

[https://leetcode.com/problems/subsets-ii/](https://leetcode.com/problems/subsets-ii/)

Given an integer array `nums` that may contain duplicates, return _all possible subsets \(the power set\)_.

The solution set **must not** contain duplicate subsets. Return the solution in **any order**.

**Example 1:**

```text
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
```

**Example 2:**

```text
Input: nums = [0]
Output: [[],[0]]
```

**Constraints:**

* `1 <= nums.length <= 10`
* `-10 <= nums[i] <= 10`

## Solution

### Sorting and Backtracking

```cpp
class Solution {
public:   
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        
        sort(nums.begin(), nums.end());  
        util(nums, res, curr, 0);
        
        return res;
    }
    
    void util(vector<int> &nums, vector<vector<int>> &res, vector<int> &curr, int start) {
        res.push_back(curr);
        for(int i = start; i < nums.size(); i++) {
	        // To avoid function calling with same value again, 
	        // to prevent duplicate subsets.
            if(i > start && nums[i] == nums[i-1]) 
                continue;  
            curr.push_back(nums[i]);
            util(nums, res, curr, i+1);
            curr.pop_back();
        }
    }
};
```

