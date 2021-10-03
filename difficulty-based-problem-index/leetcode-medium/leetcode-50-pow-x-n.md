# Leetcode 50 Pow\(x, n\)

## Problem Statement

[https://leetcode.com/problems/powx-n/](https://leetcode.com/problems/powx-n/)

Implement [pow\(x, n\)](http://www.cplusplus.com/reference/valarray/pow/), which calculates `x` raised to the power `n` \(i.e., `xn`\).

**Example 1:**

```text
Input: x = 2.00000, n = 10
Output: 1024.00000
```

**Example 2:**

```text
Input: x = 2.10000, n = 3
Output: 9.26100
```

**Example 3:**

```text
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
```

**Constraints:**

* `-100.0 < x < 100.0`
* `-2^31 <= n <= 2^31-1`
* `-10^4 <= xn <= 10^4`

## Solution

```cpp
class Solution {
public:
    double myPow(double x, int n) {
        if (n == INT_MIN) {
            return myPow(1 / x, -(n + 1)) / x;
        }
        if (n < 0) {
            return myPow(1 / x, -n);
        }
        double ans = 1;
        while (n) {
            if (n & 1) 
                ans *= x;
			      x *= x;
			      n >>= 1;
		    }
		    return ans;
    }        
};
```

