# Leetcode 461 Hamming Distance

## Problem Statement

[https://leetcode.com/problems/hamming-distance/](https://leetcode.com/problems/hamming-distance/)

The [Hamming distance](https://en.wikipedia.org/wiki/Hamming_distance) between two integers is the number of positions at which the corresponding bits are different.

Given two integers `x` and `y`, return _the **Hamming distance** between them_.

**Example 1:**

```text
Input: x = 1, y = 4
Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
The above arrows point to positions where the corresponding bits are different.
```

**Example 2:**

```text
Input: x = 3, y = 1
Output: 1
```

**Constraints:**

* `0 <= x, y <= 2^31 - 1`

## Solution

```cpp
class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x^y;
        int count = 0;
        while(n != 0)
        {
            n = n & (n-1);
            count++;
        }
        return count;
    }
};
```

