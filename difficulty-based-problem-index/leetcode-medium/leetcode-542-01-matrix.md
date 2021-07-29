# Leetcode 542 01 Matrix

## Problem Statement

[https://leetcode.com/problems/01-matrix/](https://leetcode.com/problems/01-matrix/)

Given an `m x n` binary matrix `mat`, return _the distance of the nearest_ `0` _for each cell_.

The distance between two adjacent cells is `1`.

**Example 1:** ![](https://assets.leetcode.com/uploads/2021/04/24/01-1-grid.jpg)

```text
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
```

**Example 2:** ![](https://assets.leetcode.com/uploads/2021/04/24/01-2-grid.jpg)

```text
Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
```

**Constraints:**

* `m == mat.length`
* `n == mat[i].length`
* `1 <= m, n <= 10^4`
* `1 <= m * n <= 10^4`
* `mat[i][j]` is either `0` or `1`.
* There is at least one `0` in `mat`.

## Solution

```cpp
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) 
            return matrix;
        int cols = matrix[0].size();
        vector<vector<int>> dist(rows, vector<int> (cols, INT_MAX - 100000));

        //First pass: check for left and top
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    dist[i][j] = 0;
                } else {
                    if (i > 0)
                        dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                    if (j > 0)
                        dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
                }
            }
        }

        //Second pass: check for bottom and right
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                if (i < rows - 1)
                    dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
                if (j < cols - 1)
                    dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
            }
        }
        return dist;
    }
};
```

