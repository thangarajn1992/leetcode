# Leetcode 169 Majority Element

## Problem Statement

[https://leetcode.com/problems/majority-element/](https://leetcode.com/problems/majority-element/)

Given an array `nums` of size `n`, return _the majority element_.

The majority element is the element that appears more than `⌊n / 2⌋` times. You may assume that the majority element always exists in the array.

**Example 1:**

```
Input: nums = [3,2,3]
Output: 3
```

**Example 2:**

```
Input: nums = [2,2,1,1,1,2,2]
Output: 2
```

**Constraints:**

* `n == nums.length`
* `1 <= n <= 5 * 10^4`
* `-2^31 <= nums[i] <= 2^31 - 1`

&#x20; **Follow-up:** Could you solve the problem in linear time and in `O(1)` space?

## Solution

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result = nums[0], count = 0;
        for(int i : nums)
        {
            if(count == 0)
                result = i;
            count += (result == i)? 1 : -1;
        }
        return result;
    }
};
```
