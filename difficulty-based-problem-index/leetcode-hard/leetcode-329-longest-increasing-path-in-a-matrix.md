# Leetcode 329 Longest Increasing Path in a Matrix

## Problem Statement

[https://leetcode.com/problems/longest-increasing-path-in-a-matrix/](https://leetcode.com/problems/longest-increasing-path-in-a-matrix/)

Given an `m x n` integers `matrix`, return _the length of the longest increasing path in_ `matrix`.

From each cell, you can either move in four directions: left, right, up, or down. You **may not** move **diagonally** or move **outside the boundary** \(i.e., wrap-around is not allowed\).

**Example 1:** ![](https://assets.leetcode.com/uploads/2021/01/05/grid1.jpg)

```text
Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
Output: 4
Explanation: 
The longest increasing path is [1, 2, 6, 9].
```

**Example 2:** ![](https://assets.leetcode.com/uploads/2021/01/27/tmp-grid.jpg)

```text
Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
Output: 4
Explanation: 
The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
```

**Example 3:**

```text
Input: matrix = [[1]]
Output: 1
```

**Constraints:**

* `m == matrix.length`
* `n == matrix[i].length`
* `1 <= m, n <= 200`
* `0 <= matrix[i][j] <= 2^31 - 1`

## Solution

### My Approach : DP + DFS

```cpp
class Solution {
public:
    vector<vector<int>> dp;
    vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int ans = 0;
        dp.resize(201, vector<int>(201,-1));
        
        for(int row = 0; row < matrix.size(); row++)
            for(int col = 0; col < matrix[0].size(); col++)
                ans = max(ans, dfs(matrix, row, col));
        
        return ans;
    }
    int dfs(vector<vector<int>>&matrix, int row, int col)
    {
        if(dp[row][col] != -1)
            return dp[row][col];
        
        int ans = 0;
        
        for(int d = 0; d < dir.size(); d++)
        {
            int r = row + dir[d][0];
            int c = col + dir[d][1];
            if(r >= 0 && r < matrix.size() &&
               c >= 0 && c < matrix[0].size() &&
               matrix[r][c] > matrix[row][col]) // in-bounds and increasing
                ans = max(ans, dfs(matrix, r, c));
        }
        dp[row][col] = ans + 1; // to include current element
        return dp[row][col];
    }
};
```

