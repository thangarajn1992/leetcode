# Leetcode 829 Consecutive Numbers Sum

## Problem Statement

[https://leetcode.com/problems/consecutive-numbers-sum/](https://leetcode.com/problems/consecutive-numbers-sum/)

Given an integer `n`, return _the number of ways you can write_ `n` _as the sum of consecutive positive integers._

**Example 1:**

```text
Input: n = 5
Output: 2
Explanation: 5 = 2 + 3
```

**Example 2:**

```text
Input: n = 9
Output: 3
Explanation: 9 = 4 + 5 = 2 + 3 + 4
```

**Example 3:**

```text
Input: n = 15
Output: 4
Explanation: 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5
```

**Constraints:**

* `1 <= n <= 10^9`

## Solution

```cpp
/*
Lets say consecutive numbers are: a,a+1,a+2...a+k-1
a + a+1 + a+2 + ...+ a+k-1 == n
ka + 1 + 2 + 3 +...+ k-1 == n
ka+ k*(k-1)/2 == n

a = (n- k*(k-1)/2) % k

so the values of a would be : (n-k*(k-1)/2)/k if k divides  n-k*(k-1)/2;
 
so, maximum value of k can be taken as:
n - (k *(k-1)/2() > 0
2n > k*k

*/
class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans = 0, k;
        int maxK = sqrt(2*n);
        for(k = 1; k <= maxK; k++) {
            if((n - k*(k-1)/2) % k == 0) 
                ans++;
        }   
        return ans;
    }
};
```

