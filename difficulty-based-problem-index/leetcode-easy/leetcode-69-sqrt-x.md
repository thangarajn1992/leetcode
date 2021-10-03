# Leetcode 69 Sqrt\(x\)

## Problem Statement

[https://leetcode.com/problems/sqrtx/](https://leetcode.com/problems/sqrtx/)

Given a non-negative integer `x`, compute and return _the square root of_ `x`.

Since the return type is an integer, the decimal digits are **truncated**, and only **the integer part** of the result is returned.

**Note:** You are not allowed to use any built-in exponent function or operator, such as `pow(x, 0.5)` or `x ** 0.5`.

**Example 1:**

```text
Input: x = 4
Output: 2
```

**Example 2:**

```text
Input: x = 8
Output: 2
Explanation: 
The square root of 8 is 2.82842..., and since the decimal part is truncated, 2 is returned.
```

**Constraints:**

* `0 <= x <= 2^31 - 1`

## Solution

### Binary Search Approach

```cpp
class Solution {
public:
    int mySqrt(int x) {
        int left = 1, right = x;
        int result = 0;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            // find the mid whose square is closest to x and <= x
            if(mid <= x/mid)
            {
                result = mid;
                left = mid+1;
            }
            else
            {
                right = mid-1;
            }
        }
        return result;
    }
};
```

