# Leetcode 598 Range Addition II

## Problem Statement

[https://leetcode.com/problems/range-addition-ii/](https://leetcode.com/problems/range-addition-ii/)

You are given an `m x n` matrix `M` initialized with all `0`'s and an array of operations `ops`, where `ops[i] = [ai, bi]` means `M[x][y]` should be incremented by one for all `0 <= x < ai` and `0 <= y < bi`.

Count and return _the number of maximum integers in the matrix after performing all the operations_.

**Example 1:** 

![](https://assets.leetcode.com/uploads/2020/10/02/ex1.jpg)

```text
Input: m = 3, n = 3, ops = [[2,2],[3,3]]
Output: 4
Explanation: 
The maximum integer in M is 2, and there are four of it in M. So return 4.
```

**Example 2:**

```text
Input: m = 3, n = 3, ops = [[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3],[2,2],[3,3],[3,3],[3,3]]
Output: 4
```

**Example 3:**

```text
Input: m = 3, n = 3, ops = []
Output: 9
```

**Constraints:**

* `1 <= m, n <= 4 * 10^4`
* `1 <= ops.length <= 10^4`
* `ops[i].length == 2`
* `1 <= ai <= m`
* `1 <= bi <= n`

## Solution

```cpp
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        // We need to find intersection of all ops and the answer could be
        // minimum_i * minimum_j among all ops
        int minI = m, minJ = n;
        for(vector<int> &op : ops)
        {
            if(minI > op[0])
                minI = op[0];
            if(minJ > op[1])
                minJ = op[1];
        }
        return minI * minJ;
    }
};
```

