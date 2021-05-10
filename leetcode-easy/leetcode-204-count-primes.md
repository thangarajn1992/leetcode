# Leetcode 204 Count Primes

## Problem Statement

[https://leetcode.com/problems/count-primes/](https://leetcode.com/problems/count-primes/)

Count the number of prime numbers less than a non-negative number, `n`.

**Example 1:**

```text
Input: n = 10
Output: 4
Explanation: 
There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
```

**Example 2:**

```text
Input: n = 0
Output: 0
```

**Example 3:**

```text
Input: n = 1
Output: 0
```

**Constraints:**

* `0 <= n <= 5 * 10^6`

## Solution

```cpp
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2)
            return 0;
        vector<bool> prime_check(n, true);
        int count = 1, sq = sqrt(n);
        for(int i = 3; i < n; i += 2)
        {
            if(!prime_check[i]) continue;
            count++;
            if(i <= sq)
                for(int j = i * i; j < n; j += i)
                   prime_check[j] = false;
        }
        return count;
    }
};
```

