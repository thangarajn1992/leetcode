# Leetcode 463 Island Perimeter

## Problem Statement

[https://leetcode.com/problems/island-perimeter/](https://leetcode.com/problems/island-perimeter/)

You are given `row x col` `grid` representing a map where `grid[i][j] = 1` represents land and `grid[i][j] = 0` represents water.

Grid cells are connected **horizontally/vertically** \(not diagonally\). The `grid` is completely surrounded by water, and there is exactly one island \(i.e., one or more connected land cells\).

The island doesn't have "lakes", meaning the water inside isn't connected to the water around the island. One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.

**Example 1:** ![](https://assets.leetcode.com/uploads/2018/10/12/island.png)

```text
Input: grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
Output: 16
Explanation: The perimeter is the 16 yellow stripes in the image above.
```

**Example 2:**

```text
Input: grid = [[1]]
Output: 4
```

**Example 3:**

```text
Input: grid = [[1,0]]
Output: 4
```

**Constraints:**

* `row == grid.length`
* `col == grid[i].length`
* `1 <= row, col <= 100`
* `grid[i][j]` is `0` or `1`.
* There is exactly one island in `grid`.

## Solution

```cpp
/*
    find how many 1 in the map. If without the consideration of surrounding cells, 
        the total perimeter should be the total amount of cells with 1 * 4.
    find how many cell walls that connect with both lands. 
        We need to deduct twice of those lines from total perimeter
*/
class Solution
{
    public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int totalLandCells = 0, sharedBorder = 0;
        int rows = grid.size(), cols = grid[0].size();
        for(int row = 0; row < rows; row++)
        {
            for(int col = 0; col < cols; col++)
                {
                    if(grid[row][col] == 1)
                    {
                        totalLandCells++;
                        if(row != 0 && grid[row-1][col] == 1) sharedBorder++;
                        if(col != 0 && grid[row][col-1] == 1) sharedBorder++;
                    }
                }
        }
        return (4 * totalLandCells) - (sharedBorder * 2);
    }
};
```

