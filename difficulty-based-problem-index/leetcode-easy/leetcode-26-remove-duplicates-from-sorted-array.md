# Leetcode 26 Remove Duplicates from Sorted Array

## Problem Statement

[https://leetcode.com/problems/remove-duplicates-from-sorted-array/](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)

Given a sorted array _nums_, remove the duplicates [**in-place**](https://en.wikipedia.org/wiki/In-place_algorithm) such that each element appears only _once_ and returns the new length.

Do not allocate extra space for another array, you must do this by **modifying the input array** [**in-place**](https://en.wikipedia.org/wiki/In-place_algorithm) with O\(1\) extra memory.

**Clarification:**

Confused why the returned value is an integer but your answer is an array?

Note that the input array is passed in by **reference**, which means a modification to the input array will be known to the caller as well.

**Example 1:**

```text
Input: nums = [1,1,2]
Output: 2, nums = [1,2]
Explanation: 
Your function should return length = 2, with the first two elements of 
nums being 1 and 2 respectively. 
It doesn't matter what you leave beyond the returned length.
```

**Example 2:**

```text
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4]
Explanation: 
Your function should return length = 5, with the first five elements of
nums being modified to 0, 1, 2, 3, and 4 respectively. 
It doesn't matter what values are set beyond the returned length.
```

**Constraints:**

* `0 <= nums.length <= 3 * 10^4`
* `-10^4 <= nums[i] <= 10^4`
* `nums` is sorted in ascending order.

## Solution

```cpp
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)
            return size;
        int unique = 0;
        for(int index = 1; index < nums.size() ; index++)
            if(nums[index] != nums[unique])
                nums[++unique] = nums[index];
        
        return unique+1;
    }
};
```

