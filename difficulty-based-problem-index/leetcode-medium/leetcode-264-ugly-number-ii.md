# Leetcode 264 Ugly Number II

## Problem Statement

[https://leetcode.com/problems/ugly-number-ii/](https://leetcode.com/problems/ugly-number-ii/)

An **ugly number** is a positive integer whose prime factors are limited to `2`, `3`, and `5`.

Given an integer `n`, return _the_ `nth` _**ugly number**_.

**Example 1:**

```text
Input: n = 10
Output: 12
Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first 10 ugly numbers.
```

**Example 2:**

```text
Input: n = 1
Output: 1
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
```

**Constraints:**

* `1 <= n <= 1690`

## Solution

```cpp
class Solution {
public:
    int nthUglyNumber(int n) {
        int n2 = 2, n3 = 3, n5 = 5;
        int i2 = 0, i3 = 0, i5 = 0;
        int sum[n];
        sum[0] = 1;
        for(int i = 1; i < n; i++)
        {
            sum[i] = min (n2, min(n3,n5));
            if(sum[i] == n2) n2 = 2 * sum[++i2];
            if(sum[i] == n3) n3 = 3 * sum[++i3];
            if(sum[i] == n5) n5 = 5 * sum[++i5];
        }
        return sum[n-1];
    }
};
```

