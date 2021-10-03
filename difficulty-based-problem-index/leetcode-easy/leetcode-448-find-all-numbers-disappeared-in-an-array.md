# Leetcode 448 Find All Numbers Disappeared in an Array

## Problem Statement

[https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)

Given an array `nums` of `n` integers where `nums[i]` is in the range `[1, n]`, return _an array of all the integers in the range_ `[1, n]` _that do not appear in_ `nums`.

**Example 1:**

```text
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
```

**Example 2:**

```text
Input: nums = [1,1]
Output: [2]
```

**Constraints:**

* `n == nums.length`
* `1 <= n <= 10^5`
* `1 <= nums[i] <= n`

**Follow up:** Could you do it without extra space and in `O(n)` runtime? You may assume the returned list does not count as extra space.

## Solution

### O\(n\) Time and O\(1\) Space Complexity

```cpp
class Solution {
public:   
/* 
O(N) time and O(1) space complexity :
    First iteration to negate values at position whose equal to values appear in array. 
    Second iteration to collect all position whose value is positive, which are the missing values. 
*/
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int len = nums.size();
        for(int index = 0; index < len; index++) {
            int actualindex = abs(nums[index]) - 1; // index start from 0
            if(nums[actualindex] > 0)
                nums[actualindex] = -nums[actualindex];
        }
        vector<int> res;
        for(int index = 0; index < len; index++) {
            if(nums[index] > 0) 
                res.push_back(index+1);
        }
        return res;
    }
};
```

### O\(n\) Time and Space Complexity

```cpp
class Solution {
public:  
/* O(N) time and space Complexity */
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<bool> present(nums.size() + 1, false);
        for(int num : nums)
            present[num] = true;
        
        vector<int> disappeared;
        for(int index = 1; index <= nums.size(); index++)
            if(present[index] == false)
                disappeared.push_back(index);
        
        return disappeared;
    }
};
```

