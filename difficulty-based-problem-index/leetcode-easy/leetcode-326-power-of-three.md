# Leetcode 326 Power of Three

## Problem Statement

[https://leetcode.com/problems/power-of-three/](https://leetcode.com/problems/power-of-three/)

Given an integer `n`, return _`true` if it is a power of three. Otherwise, return `false`_.

An integer `n` is a power of three, if there exists an integer `x` such that `n == 3^x`.

**Example 1:**

```
Input: n = 27
Output: true
```

**Example 2:**

```
Input: n = 0
Output: false
```

**Example 3:**

```
Input: n = 9
Output: true
```

**Example 4:**

```
Input: n = 45
Output: false
```

**Constraints:**

* `-2^31 <= n <= 2^31 - 1`

&#x20; **Follow up:** Could you solve it without loops/recursion?

## Solution

```cpp
class Solution {
public:
    bool isPowerOfThree(int n) {
        //Maximum 3 power within integer range is 3^19 = 1162261467
        return (n && (1162261467 % n == 0));
    }
};
```
