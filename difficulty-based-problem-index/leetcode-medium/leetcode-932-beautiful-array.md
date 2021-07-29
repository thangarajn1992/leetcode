# Leetcode 932 Beautiful Array

## Problem Statement

[https://leetcode.com/problems/beautiful-array/](https://leetcode.com/problems/beautiful-array/)

An array `nums` of length `n` is **beautiful** if:

* `nums` is a permutation of the integers in the range `[1, n]`.
* For every `0 <= i < j < n`, there is no index `k` with `i < k < j` where `2 * nums[k] == nums[i] + nums[j]`.

Given the integer `n`, return _any **beautiful** array_ `nums` _of length_ `n`. There will be at least one valid answer for the given `n`.

**Example 1:**

```text
Input: n = 4
Output: [2,1,4,3]
```

**Example 2:**

```text
Input: n = 5
Output: [3,1,2,5,4]
```

**Constraints:**

* `1 <= n <= 1000`

## Solution

### Approach

Looking at the elements `1, 2, ..., N`, there are `(N+1) / 2` odd numbers and `N / 2` even numbers.

We solve for elements `1, 2, ..., (N+1) / 2` and map these numbers onto `1, 3, 5, ...`. Similarly, we solve for elements `1, 2, ..., N/2` and map these numbers onto `2, 4, 6, ...`.

We can compose these solutions by concatenating them, since an arithmetic sequence never starts and ends with elements of different parity.

We memoize the result to arrive at the answer quicker.

```cpp
class Solution {
public:
    vector<vector<int>> memo;
    vector<int> beautifulArray(int n) {
        memo.resize(n+1, {});
        return calc(n);
    }
    vector<int> calc(int n)
    {
        if(memo[n].size())
            return memo[n];
        
        vector<int> result(n);
        if(n == 1)
            return {1};
        else
        {
            int t = 0;
            for(int x : calc((n+1)/2))
                result[t++] = (2*x) - 1;
            for(int x : calc((n/2)))
                result[t++] = 2*x;
        }
        memo[n] = result;
        return result;
    }
};
```

