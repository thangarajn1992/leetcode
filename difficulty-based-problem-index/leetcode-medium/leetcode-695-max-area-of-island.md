# Leetcode 695 Max Area of Island

## Problem Statement

[https://leetcode.com/problems/max-area-of-island/](https://leetcode.com/problems/max-area-of-island/)

You are given an `m x n` binary matrix `grid`. An island is a group of `1`'s \(representing land\) connected **4-directionally** \(horizontal or vertical.\) You may assume all four edges of the grid are surrounded by water.

The **area** of an island is the number of cells with a value `1` in the island.

Return _the maximum **area** of an island in_ `grid`. If there is no island, return `0`.

**Example 1:** ![](https://assets.leetcode.com/uploads/2021/05/01/maxarea1-grid.jpg)

```text
Input: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
Output: 6
Explanation: 
The answer is not 11, because the island must be connected 4-directionally.
```

**Example 2:**

```text
Input: grid = [[0,0,0,0,0,0,0,0]]
Output: 0
```

**Constraints:**

* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 50`
* `grid[i][j]` is either `0` or `1`.

## Solution

### Recursive Approach

```cpp
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_area = 0;
        int row_size = grid.size();
        int col_size = grid[0].size();
        int row_side[4] = { -1, 1, 0, 0 };
        int col_side[4] = { 0, 0, 1, -1 };
        for(int r = 0; r < row_size; r++)
        {
            for(int c = 0; c < col_size; c++)
            {
                if(grid[r][c] == 0)
                    continue;
                stack<pair<int,int>> s;
                s.push(make_pair(r,c));
                grid[r][c] = 0;
                int area = 0;
                while(!s.empty())
                {
                    auto e = s.top();
                    s.pop();
                    area++;
                    for(int k = 0; k < 4; k++)
                    {
                        int cr = e.first + row_side[k];
                        int cc = e.second + col_side[k];
                        if(cr >= 0 && cr < row_size &&
                           cc >= 0 && cc < col_size &&
                           grid[cr][cc])
                        {
                            s.push(make_pair(cr,cc));
                            grid[cr][cc] = 0;
                        }
                    }
                }
                max_area = max(max_area, area);
            }
        }
        return max_area;
    }
};
```

### Recursive Approach

```cpp
class Solution {
public:
    vector<vector<int>> dir{{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    int dfsArea(int i, int j, vector<vector<int>> &grid)
    {
        grid[i][j] = 0;
        int area = 1;
        for (int d = 0; d < dir.size(); d++)
        {
            int r = i + dir[d][0];
            int c = j + dir[d][1];
            if (r >= 0 && c >= 0 && r < grid.size() && c < grid[0].size() && 
                grid[r][c] == 1)
                area += dfsArea(r, c, grid);
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int area = 0;
    
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[0].size(); j++)
                if (grid[i][j] == 1)
                    area = max(area, dfsArea(i, j, grid));

        return area;
    }
```

