# Leetcode 64 Minimum Path Sum

## Problem Statement

[https://leetcode.com/problems/minimum-path-sum/](https://leetcode.com/problems/minimum-path-sum/)

Given a `m x n` `grid` filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

**Note:** You can only move either down or right at any point in time.

**Example 1:** ![](https://assets.leetcode.com/uploads/2020/11/05/minpath.jpg)

```
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.
```

**Example 2:**

```
Input: grid = [[1,2,3],[4,5,6]]
Output: 12
```

**Constraints:**

* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 200`
* `0 <= grid[i][j] <= 100`

## Solution

### 2D dp vector

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<vector<int>> mini(rows, vector<int>(cols, INT_MAX));
        
        // first cell
        mini[0][0] = grid[0][0];
        
        // first row
        for(int col = 1; col < cols; col++)
            mini[0][col] = mini[0][col-1] + grid[0][col];
        
        // first col
        for(int row = 1; row < rows; row++)
            mini[row][0] = mini[row-1][0] + grid[row][0];
        
        // for other cells
        for(int row = 1; row < rows; row++)
            for(int col = 1; col < cols; col++)
                mini[row][col] = min(mini[row-1][col], mini[row][col-1]) + grid[row][col];
        
        return mini[rows-1][cols-1];
        
    }
};
```

### 1D Vector DP

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

### In-Place modification

```cpp
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        
        // first row
        for(int col = 1; col < cols; col++)
            grid[0][col] += grid[0][col-1];
        
        // first col
        for(int row = 1; row < rows; row++)
            grid[row][0] += grid[row-1][0];
        
        // for other cells
        for(int row = 1; row < rows; row++)
            for(int col = 1; col < cols; col++)
                grid[row][col] += min(grid[row-1][col], grid[row][col-1]);
        
        return grid[rows-1][cols-1];    
    }
};
```
