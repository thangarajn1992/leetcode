# Leetcode 1913 Maximum Product Difference Between Two Pairs

## Problem Statement

[https://leetcode.com/problems/maximum-product-difference-between-two-pairs/](https://leetcode.com/problems/maximum-product-difference-between-two-pairs/)

The **product difference** between two pairs `(a, b)` and `(c, d)` is defined as `(a * b) - (c * d)`.

* For example, the product difference between `(5, 6)` and `(2, 7)` is `(5 * 6) - (2 * 7) = 16`.

Given an integer array `nums`, choose four **distinct** indices `w`, `x`, `y`, and `z` such that the **product difference** between pairs `(nums[w], nums[x])` and `(nums[y], nums[z])` is **maximized**.

Return _the **maximum** such product difference_.

**Example 1:**

```text
Input: nums = [5,6,2,7,4]
Output: 34
Explanation: 
We can choose indices 1 and 3 for the first pair (6, 7) and 
indices 2 and 4 for the second pair (2, 4).
The product difference is (6 * 7) - (2 * 4) = 34.
```

**Example 2:**

```text
Input: nums = [4,2,5,9,7,4,8]
Output: 64
Explanation: 
We can choose indices 3 and 6 for the first pair (9, 8) and 
indices 1 and 5 for the second pair (2, 4).
The product difference is (9 * 8) - (2 * 4) = 64.
```

**Constraints:**

* `4 <= nums.length <= 10^4`
* `1 <= nums[i] <= 10^4`

## Solution

### One Pass without sorting

```cpp
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        //we have to return the result of
        // (firstMax*secondMax) - (firstMin*secondMin)
        int max1 = INT_MIN, max2 = INT_MIN;
        int min1 = INT_MAX, min2 = iNT_MAX;

        for(int num : nums)
        {       
            if(num > max1)
            {
                //assign the second max to max2
                max2 = max1;
                max1 = num;
            }
            else if(num > max2)
            {
                //it can become second max
                max2 = num;
            }
            
            //check for the minimum
            if(num < min1)
            {
                //it can become first minimum
                min2 = min1;
                min1 = num;
            }
            else if(num < min2)
            {
                //it can become second minimum
                min2 = num;
            }
        }
        return (max1 * max2) - (min1 * min2);
    }
};
```

### With sorting

```cpp
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return (nums[nums.size()-1] * nums[nums.size()-2]) - (nums[0] * nums[1]);
    }
};
```

