# Leetcode 7 Reverse Integer

## Problem Statement

[https://leetcode.com/problems/reverse-integer/](https://leetcode.com/problems/reverse-integer/)

Given a signed 32-bit integer `x`, return `x` _with its digits reversed_. If reversing `x` causes the value to go outside the signed 32-bit integer range `[-2^31, 2^31 - 1]`, then return `0`.

**Assume the environment does not allow you to store 64-bit integers \(signed or unsigned\).**

**Example 1:**

```text
Input: x = 123
Output: 321
```

**Example 2:**

```text
Input: x = -123
Output: -321
```

**Example 3:**

```text
Input: x = 120
Output: 21
```

**Example 4:**

```text
Input: x = 0
Output: 0
```

**Constraints:**

* `-2^31 <= x <= 2^31 - 1`

## Solution

```cpp
class Solution {
public:
    int reverse(int x){
        int rev = 0;
        while( x != 0)
        {
            int pop = x % 10;
            x /= 10;
            if( rev > INT_MAX/10 || (rev == INT_MAX/10 && pop > 7)) return 0;
            if( rev < INT_MIN/10 || (rev == INT_MIN/10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};
```

