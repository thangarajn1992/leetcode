# Leetcode 136 Single Number

## Problem Statement

[https://leetcode.com/problems/single-number/](https://leetcode.com/problems/single-number/)

Given a **non-empty** array of integers, `nums`, every element appears _twice_ except for one. Find that single one.

**Follow up:** Could you implement a solution with a linear runtime complexity and without using extra memory?

**Example 1:**

```text
Input: nums = [2,2,1]
Output: 1
```

**Example 2:**

```text
Input: nums = [4,1,2,1,2]
Output: 4
```

**Example 3:**

```text
Input: nums = [1]
Output: 1
```

**Constraints:**

* `1 <= nums.length <= 3 * 10^4`
* `-3 * 10^4 <= nums[i] <= 3 * 10^4`
* Each element in the array appears twice except for one element which appears only once.

### Explanation

#### Bit Manipulation Concept

* If we take XOR of zero and some bit, it will return that bit
  * a ^ 0 = a  
* If we take XOR of two same bits, it will return 0
  * a ^ a = 0
* a ^ b ^ a = \(a ^ a\) ^ b = 0 ^ b = b

So we can XOR all bits together to find the unique number.

## Solution

```cpp
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0;
        for(int i : nums)
            a ^= i;
        return a;
    }
};
```

