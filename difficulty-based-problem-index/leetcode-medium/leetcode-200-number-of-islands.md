# Leetcode 200 Number of Islands

## Problem Statement

[https://leetcode.com/problems/number-of-islands/](https://leetcode.com/problems/number-of-islands/)

Given an `m x n` 2D binary grid `grid` which represents a map of `'1'`s \(land\) and `'0'`s \(water\), return _the number of islands_.

An **island** is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

**Example 1:**

```text
Input: grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
Output: 1
```

**Example 2:**

```text
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
Output: 3
```

**Constraints:**

* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 300`
* `grid[i][j]` is `'0'` or `'1'`.

## Solution

### Recursive Approach

```cpp
class Solution {
public:
    vector<vector<int>> dir = {{-1,0}, {1, 0}, {0, 1}, {0, -1}};
    void cover_island(int row, int col, vector<vector<char>>& grid)
    {
        grid[row][col] = '0';
        for(int i = 0; i < dir.size(); i++)
        {
            int r = row + dir[i][0];
            int c = col + dir[i][1];
            if( r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() &&
                grid[r][c] == '1')
                cover_island(r, c, grid);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int island = 0;
        for(int row = 0; row < grid.size(); row++)
        {
            for(int col = 0; col < grid[0].size(); col++)
            {
                if(grid[row][col] == '1')
                {
                    cover_island(row,col,grid);
                    island++;
                }
            }
        }
        return island;
    }
};
```

### Iterative Approach

```cpp
class Solution {
public:
    vector<vector<int>> dir = {{-1,0}, {1, 0}, {0, 1}, {0, -1}};
    int numIslands(vector<vector<char>>& grid) {
        int island = 0;
        for(int row = 0; row < grid.size(); row++)
        {
            for(int col = 0; col < grid[0].size(); col++)
            {
                if(grid[row][col] == '1')
                {
                    island++;
                    stack<pair<int,int>> s;
                    s.push(make_pair(row,col));
                    grid[row][col] = '0';
                    while(!s.empty())
                    {
                        auto e = s.top();
                        s.pop();
                        for(int d = 0; d < dir.size(); d++)
                        {
                            int r = e.first + dir[d][0];
                            int c = e.second + dir[d][1];
                            if( r >= 0 && r < grid.size() &&
                                c >= 0 && c < grid[0].size() &&
                                grid[r][c] == '1')
                            {
                                s.push(make_pair(r,c));
                                grid[r][c] = '0';
                            }
                        }
                    }
                }
            }
        }
        return island;
    }
```

