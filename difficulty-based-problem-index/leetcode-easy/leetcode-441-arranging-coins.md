# Leetcode 441 Arranging Coins

## Problem Statement

[https://leetcode.com/problems/arranging-coins/](https://leetcode.com/problems/arranging-coins/)

You have `n` coins and you want to build a staircase with these coins. The staircase consists of `k` rows where the `ith` row has exactly `i` coins. The last row of the staircase **may be** incomplete.

Given the integer `n`, return _the number of **complete rows** of the staircase you will build_.

&#x20;

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/04/09/arrangecoins1-grid.jpg)

```
Input: n = 5
Output: 2
Explanation: Because the 3rd row is incomplete, we return 2.
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/04/09/arrangecoins2-grid.jpg)

```
Input: n = 8
Output: 3
Explanation: Because the 4th row is incomplete, we return 3.
```

&#x20;

**Constraints:**

* `1 <= n <= 2^31 - 1`

## Solution

### Binary Search Approach

```cpp
class Solution {
public:
    int arrangeCoins(int n) {
        long left = 1, right = n;
        int completerows = 1;
        while(left <= right)
        {
            long mid = left + (right - left)/2;
            long sum = (mid * (mid+1))/2;
            
            if(sum == n)
                return mid;
            else if(sum < n)
            {
                completerows = mid;
                left = mid + 1;
            }
            else
                right = mid - 1;
        }
        return completerows;
    }
};
```

### Mathematical Approach

The constraint of the problem can be expressed as :

$$
k * \left( k +1 \right) \le 2N
$$

This could be solved by [completing the square](https://en.wikipedia.org/wiki/Completing\_the\_square) technique,

$$
\left(k + \frac{1}{2}\right)^2 - \frac{1}{4} \le 2N
$$

that results in the following answer:

$$
k = \left[\sqrt{2N + \frac{1}{4}} - \frac{1}{2}\right]
$$

```cpp
class Solution {
public:
    int arrangeCoins(int n) {
        return (int) (sqrt(2 * (long)n  + 0.25) - 0.5);
    }
};
```
