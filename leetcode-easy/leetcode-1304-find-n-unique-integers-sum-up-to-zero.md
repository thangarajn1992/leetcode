# Leetcode 1304 Find N Unique Integers Sum up to Zero

## Problem Statement

[https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/](https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/)

Given an integer `n`, return **any** array containing `n` **unique** integers such that they add up to `0`.

**Example 1:**

```text
Input: n = 5
Output: [-7,-1,1,3,4]
Explanation: 
These arrays also are accepted [-5,-1,1,2,3] , [-3,-1,2,-2,4].
```

**Example 2:**

```text
Input: n = 3
Output: [-1,0,1]
```

**Example 3:**

```text
Input: n = 1
Output: [0]
```

**Constraints:**

* `1 <= n <= 1000`

## Solution

```cpp
class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> result(n,0);
        int mid = n/2;
        for(int i = 0; i < n/2; i++)
        {
            result[i] = -mid;
            result[n-1-i] = mid--;
        }
        return result;
    }
};
```

