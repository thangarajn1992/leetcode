# Leetcode 64 Minimum Path Sum

## Problem Statement

[https://leetcode.com/problems/minimum-path-sum/](https://leetcode.com/problems/minimum-path-sum/)

Given a `m x n` `grid` filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

**Note:** You can only move either down or right at any point in time.

**Example 1:** ![](https://assets.leetcode.com/uploads/2020/11/05/minpath.jpg)

```text
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
```

**Example 2:**

```text
Input: grid = [[1,2,3],[4,5,6]]
Output: 12
```

**Constraints:**

* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 200`
* `0 <= grid[i][j] <= 100`

## Solution

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<int> dp(grid[0].size(), 0);
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(i == 0 && j == 0) dp[j] = grid[i][j];
                else if(i == 0) dp[j] = dp[j-1] + grid[i][j];
                else if(j == 0) dp[j] = dp[j] + grid[i][j];
                else dp[j] = min(dp[j],dp[j-1]) + grid[i][j];
            }
        }
        return dp.back();        
    }
};
```

