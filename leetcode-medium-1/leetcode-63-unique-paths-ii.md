# Leetcode 63 Unique Paths II

## Problem Statement

[https://leetcode.com/problems/unique-paths-ii/](https://leetcode.com/problems/unique-paths-ii/)

A robot is located at the top-left corner of a `m x n` grid \(marked 'Start' in the diagram below\).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid \(marked 'Finish' in the diagram below\).

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and space is marked as `1` and `0` respectively in the grid.

**Example 1:** ![](https://assets.leetcode.com/uploads/2020/11/04/robot1.jpg)

```text
Input: obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
Output: 2
Explanation: 
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right
```

**Example 2:** ![](https://assets.leetcode.com/uploads/2020/11/04/robot2.jpg)

```text
Input: obstacleGrid = [[0,1],[0,0]]
Output: 1
```

**Constraints:**

* `m == obstacleGrid.length`
* `n == obstacleGrid[i].length`
* `1 <= m, n <= 100`
* `obstacleGrid[i][j]` is `0` or `1`.

## Solution

```text
int uniquePathsWithObstacles(vector<vector<int>>& G) {
    int m = G.size();
    int n = G[0].size();
    G[0][0] ^= 1;
    for (int i = 1; i < n; i++)
        G[0][i] = G[0][i]? 0 : G[0][i-1]; 
    for(int i = 1; i < m; i++) 
    {
        G[i][0] = G[i][0]? 0 : G[i-1][0];
        for(int j = 1; j < n; j++)
            G[i][j] = G[i][j] ? 0 : G[i-1][j] + G[i][j-1];
    }
    return G[m-1][n-1];      
}
```

