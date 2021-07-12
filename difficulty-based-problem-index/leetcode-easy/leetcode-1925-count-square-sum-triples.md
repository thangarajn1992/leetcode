# Leetcode 1925 Count Square Sum Triples

## Problem Statement

[https://leetcode.com/problems/count-square-sum-triples/](https://leetcode.com/problems/count-square-sum-triples/)

A **square triple** `(a,b,c)` is a triple where `a`, `b`, and `c` are **integers** and `a2 + b2 = c2`.

Given an integer `n`, return _the number of **square triples** such that_ `1 <= a, b, c <= n`.

**Example 1:**

```text
Input: n = 5
Output: 2
Explanation: The square triples are (3,4,5) and (4,3,5).
```

**Example 2:**

```text
Input: n = 10
Output: 4
Explanation: The square triples are (3,4,5), (4,3,5), (6,8,10), and (8,6,10).
```

**Constraints:**

* `1 <= n <= 250`

## Solution

### My Modified Binary Search Optimised Solutionn

```cpp
class Solution {
public:
    int countTriples(int n) {
        int ans = 0;
        for(int first = 1; first <= n; first++)
        {
            int first_sq = first*first;
            for(int second = first+1; second <= n; second++)
            {
                int sum_sq = first_sq + second*second;
                if(sum_sq <= n*n)
                    ans += isSquare(n, sum_sq, second+1);
            }
        }
        return ans*2;
    }    
    bool isSquare(int n, int square, int start) {
        int low = start, high = n;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(mid * mid == square)
                return true;
            if(mid * mid > square)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low*low == square;
    }
};
```

