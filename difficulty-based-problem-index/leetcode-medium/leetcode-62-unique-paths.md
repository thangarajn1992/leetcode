# Leetcode 62 Unique Paths

## Problem Statement

[https://leetcode.com/problems/unique-paths/](https://leetcode.com/problems/unique-paths/)

A robot is located at the top-left corner of a `m x n` grid \(marked 'Start' in the diagram below\).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid \(marked 'Finish' in the diagram below\).

How many possible unique paths are there?

**Example 1:** ![](https://assets.leetcode.com/uploads/2018/10/22/robot_maze.png)

```text
Input: m = 3, n = 7
Output: 28
```

**Example 2:**

```text
Input: m = 3, n = 2
Output: 3
Explanation:
From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
```

**Example 3:**

```text
Input: m = 7, n = 3
Output: 28
```

**Example 4:**

```text
Input: m = 3, n = 3
Output: 6
```

**Constraints:**

* `1 <= m, n <= 100`
* It's guaranteed that the answer will be less than or equal to `2 * 10^9`.

## Solution

```cpp
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 0);
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(i == 0 && j == 0) dp[j] = 1;
                else if(i == 0) dp[j] = dp[j-1];
                else if(j == 0) continue;
                else dp[j] = dp[j] + dp[j-1];
            }
        }
        return dp[n-1];
    }
};
```

