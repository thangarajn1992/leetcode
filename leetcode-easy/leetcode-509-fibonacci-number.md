# Leetcode 509 Fibonacci Number

## Problem Statement

[https://leetcode.com/problems/fibonacci-number/](https://leetcode.com/problems/fibonacci-number/)

The **Fibonacci numbers**, commonly denoted `F(n)` form a sequence, called the **Fibonacci sequence**, such that each number is the sum of the two preceding ones, starting from `0` and `1`. That is,

```text
F(0) = 0, F(1) = 1
F(n) = F(n - 1) + F(n - 2), for n > 1.
```

Given `n`, calculate `F(n)`.

**Example 1:**

```text
Input: n = 2
Output: 1
Explanation: 
F(2) = F(1) + F(0) = 1 + 0 = 1.
```

**Example 2:**

```text
Input: n = 3
Output: 2
Explanation: 
F(3) = F(2) + F(1) = 1 + 1 = 2.
```

**Example 3:**

```text
Input: n = 4
Output: 3
Explanation: 
F(4) = F(3) + F(2) = 2 + 1 = 3.
```

**Constraints:**

* `0 <= n <= 30`

## Solution

### Iterative Approach

```cpp
class Solution {
public:
    int fib(int n) {
        if(n <= 1)
            return n;
        int a = 0, b = 1, c;
        for(int i = 2; i <= n; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};
```

### Dynamic Programming Approach

```cpp
class Solution {
public:
    int fib(int n) {
        int fib[n+2];
        fib[0] = 0;
        fib[1] = 1;
        for(int i = 2; i <= n; i++)
            fib[i] = fib[i-1] + fib[i-2];
        return fib[n];
    }
};
```

