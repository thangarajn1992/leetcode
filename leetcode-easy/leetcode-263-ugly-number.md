# Leetcode 263 Ugly Number

## Problem Statement

[https://leetcode.com/problems/ugly-number/](https://leetcode.com/problems/ugly-number/)

An **ugly number** is a positive integer whose prime factors are limited to `2`, `3`, and `5`.

Given an integer `n`, return `true` _if_ `n` _is an **ugly number**_.

**Example 1:**

```text
Input: n = 6
Output: true
Explanation: 6 = 2 × 3
```

**Example 2:**

```text
Input: n = 8
Output: true
Explanation: 8 = 2 × 2 × 2
```

**Example 3:**

```text
Input: n = 14
Output: false
Explanation: 14 is not ugly since it includes the prime factor 7.
```

**Example 4:**

```text
Input: n = 1
Output: true
Explanation: 1 has no prime factors, therefore all of its prime factors are limited to 2, 3, and 5.
```

**Constraints:**

* `-2^31 <= n <= 2^31 - 1`

## Solution

```cpp
class Solution {
public:
    bool isUgly(int n) {
        if(n <= 0)
            return false;
        for(int x:{2,3,5}) 
            while(n % x == 0) 
                n /= x;
        return (n==1)? true: false;
    }
};
```

