# Leetcode 633 Sum of Square Numbers

## Problem Statement

[https://leetcode.com/problems/sum-of-square-numbers/](https://leetcode.com/problems/sum-of-square-numbers/)

Given a non-negative integer `c`, decide whether there're two integers `a` and `b` such that `a2 + b2 = c`.

**Example 1:**

```text
Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5
```

**Example 2:**

```text
Input: c = 3
Output: false
```

**Example 3:**

```text
Input: c = 4
Output: true
```

**Example 4:**

```text
Input: c = 2
Output: true
```

**Example 5:**

```text
Input: c = 1
Output: true
```

**Constraints:**

* `0 <= c <= 2^31 - 1`

## Solution

### Binary Search

```cpp
class Solution {
public:
    bool judgeSquareSum(int c) {
        for (long a = 0; a * a <= c; a++) {
            int b = c - (int)(a * a);
            if (binary_search(0, b, b))
                return true;
        }
        return false;
    }
    bool binary_search(long start, long end, int n) {
        if (start > end)
            return false;
        long mid = start + (end - start) / 2;
        if (mid * mid == n)
            return true;
        if (mid * mid > n)
            return binary_search(start, mid - 1, n);
        else
            return binary_search(mid + 1, end, n);
    }       
};
```

### Fermat Theorem

This approach is based on the following statement, which is based on Fermat's Theorem:

> Any positive number n is expressible as a sum of two squares if and only if the prime factorization o fn, every prime of the form \(4k+3\) occurs an even number of times.

By making use of the above theorem, we can directly find out if the given number c can be expressed as a sum of two squares.

To do so we simply find all the prime factors of the given number c, which could range from \[2, sqrt\(c\)\] along with the count of those factors, by repeated division. If at any step, we find out that the number of occurrences of any prime factor of the form\(4k+3\) occurs an odd number of times, we can return a False value.

In case, c itself is a prime number, it won't be divisible by any of the primes in the \[2, sqrt\(c\)\]. Thus, we need to check if c can be expressed in the form of 4k+3. If so, we need to return a False value, indicating that this prime occurs an odd number\(1\) of times.

Otherwise, we can return a True value.

```cpp
class Solution {
public:
    bool judgeSquareSum(int c) {
        for (int i = 2; i * i <= c; i++) {
            int count = 0;
            if (c % i == 0) {
                while (c % i == 0) {
                    count++;
                    c /= i;
                }
                if (i % 4 == 3 && count % 2 != 0)
                    return false;
            }
        }
        return c % 4 != 3;
    }
};
```

