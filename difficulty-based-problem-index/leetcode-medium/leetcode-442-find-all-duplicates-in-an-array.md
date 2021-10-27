# Leetcode 442 Find All Duplicates in an Array

## Problem Statement

[https://leetcode.com/problems/find-all-duplicates-in-an-array/](https://leetcode.com/problems/find-all-duplicates-in-an-array/)

Given an integer array `nums` of length `n` where all the integers of `nums` are in the range `[1, n]` and each integer appears **once** or **twice**, return _an array of all the integers that appears **twice**_.

You must write an algorithm that runs in `O(n) `time and uses only constant extra space.

**Example 1:**

```
Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
```

**Example 2:**

```
Input: nums = [1,1,2]
Output: [1]
```

**Example 3:**

```
Input: nums = [1]
Output: []
```

**Constraints:**

* `n == nums.length`
* `1 <= n <= 10^5`
* `1 <= nums[i] <= n`
* Each element in `nums` appears **once** or **twice**.

## Solution

#### Algorithm

1. When we encounter a number i, flip the number at position i-1 to negative
2. If the number at position i-1 is already negative, then i is the number that occurs twice.

```cpp
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int size = nums.size();
        vector<int> duplicates;
        for(int index = 0; index < size; index++)
        {
            int val = abs(nums[index]);
            
            if(nums[val-1] < 0)
                duplicates.push_back(val);
            else
                nums[val-1] = -nums[val-1];
        }
        return duplicates;
    }
};
```
