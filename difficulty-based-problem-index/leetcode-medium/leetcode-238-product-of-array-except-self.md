# Leetcode 238 - Product of Array Except Self

## Problem Statement

[https://leetcode.com/problems/product-of-array-except-self/](https://leetcode.com/problems/product-of-array-except-self/)

Given an integer array `nums`, return _an array_ `answer` _such that_ `answer[i]` _is equal to the product of all the elements of_ `nums` _except_ `nums[i]`.

The product of any prefix or suffix of `nums` is **guaranteed** to fit in a **32-bit** integer.

You must write an algorithm that runs in `O(n)` time and without using the division operation.

**Example 1:**

```
Input: nums = [1,2,3,4]
Output: [24,12,8,6]
```

**Example 2:**

```
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
```

&#x20;

**Constraints:**

* `2 <= nums.length <= 10^5`
* `-30 <= nums[i] <= 30`
* The product of any prefix or suffix of `nums` is **guaranteed** to fit in a **32-bit** integer.

**Follow up:** Can you solve the problem in `O(1) `extra space complexity? (The output array **does not** count as extra space for space complexity analysis.)

## Solution

```cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size,1);
        
        int productFromStart = 1;
        int productFromEnd = 1;
        
        for(int i = 0; i < size; i++)
        {
            result[i] *= productFromStart;
            productFromStart *= nums[i];
            
            result[size-1-i] *= productFromEnd;
            productFromEnd *= nums[size-1-i];
        }
        
        return result;
    }
};
```
