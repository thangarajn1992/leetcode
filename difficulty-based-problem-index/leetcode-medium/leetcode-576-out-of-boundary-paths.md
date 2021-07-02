# Leetcode 576 Out of Boundary Paths

## Problem Statement

[https://leetcode.com/problems/out-of-boundary-paths/](https://leetcode.com/problems/out-of-boundary-paths/)

There is an `m x n` grid with a ball. The ball is initially at the position `[startRow, startColumn]`. You are allowed to move the ball to one of the four adjacent four cells in the grid \(possibly out of the grid crossing the grid boundary\). You can apply **at most** `maxMove` moves to the ball.

Given the five integers `m`, `n`, `maxMove`, `startRow`, `startColumn`, return the number of paths to move the ball out of the grid boundary. Since the answer can be very large, return it **modulo** `109 + 7`.

**Example 1:** 

![](https://assets.leetcode.com/uploads/2021/04/28/out_of_boundary_paths_1.png)

```text
Input: m = 2, n = 2, maxMove = 2, startRow = 0, startColumn = 0
Output: 6
```

**Example 2:** 

![](https://assets.leetcode.com/uploads/2021/04/28/out_of_boundary_paths_2.png)

```text
Input: m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1
Output: 12
```

**Constraints:**

* `1 <= m, n <= 50`
* `0 <= maxMove <= 50`
* `0 <= startRow <= m`
* `0 <= startColumn <= n`

## Solution

```cpp
class Solution {
public:
    int mod = pow(10,9)+7;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));
        return findallPaths(m, n, maxMove, startRow, startColumn, memo);
    }
    
    int findallPaths(int m, int n, int moves_left, int row, int col, 
                     vector<vector<vector<int>>> &memo)
    {
        // We went outside of boundary
        if(row == m || row < 0 || col == n || col < 0)
            return 1;
        
        // We ran out of moves!!
        if(moves_left == 0)
            return 0;
        
        if(memo[row][col][moves_left] >= 0)
            return memo[row][col][moves_left];
        
        memo[row][col][moves_left] = 
            (
             (findallPaths(m, n, moves_left - 1, row+1, col, memo) + 
              findallPaths(m,n, moves_left - 1, row-1, col, memo)) % mod +
             (findallPaths(m, n, moves_left - 1, row, col+1, memo) +
              findallPaths(m, n, moves_left - 1, row, col-1, memo)) %mod 
            ) % mod;
        
        return memo[row][col][moves_left];
    }
};
```

