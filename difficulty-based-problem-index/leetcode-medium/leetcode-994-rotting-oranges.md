# Leetcode 994 Rotting Oranges

## Problem Statement

[https://leetcode.com/problems/rotting-oranges/](https://leetcode.com/problems/rotting-oranges/)

You are given an `m x n` `grid` where each cell can have one of three values:

* `0` representing an empty cell,
* `1` representing a fresh orange, or
* `2` representing a rotten orange.

Every minute, any fresh orange that is **4-directionally adjacent** to a rotten orange becomes rotten.

Return _the minimum number of minutes that must elapse until no cell has a fresh orange_. If _this is impossible, return_ `-1`.

**Example 1:**

![](https://assets.leetcode.com/uploads/2019/02/16/oranges.png)

```
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
```

**Example 2:**

```
Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: 
The orange in the bottom left corner (row 2, column 0) is never rotten, 
because rotting only happens 4-directionally.
```

**Example 3:**

```
Input: grid = [[0,2]]
Output: 0
Explanation: 
Since there are already no fresh oranges at minute 0, the answer is just 0.
```

**Constraints:**

* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 10`
* `grid[i][j]` is `0`, `1`, or `2`.

## Solution

### Queue Based BFS

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minutes = 0;
        queue<pair<int,int>> q;
        int freshOrangesCnt = 0;
        // push all rotten oranges into the queue
        for(int row = 0; row < grid.size(); row++)
        {
            for(int col = 0; col < grid[0].size(); col++)
            {
                if(grid[row][col] == 2)
                    q.push({row, col});
                if(grid[row][col] == 1)
                    freshOrangesCnt++;
            }
        }
        while(q.empty() == false && freshOrangesCnt > 0)
        {
            minutes++;
            int size = q.size();
            
            while(size > 0)
            {
                int currentRow = q.front().first;
                int currentCol = q.front().second;
                
                // check all its adjacent cells
                if(currentRow - 1 >= 0 && grid[currentRow - 1][currentCol] == 1)
                {
                    grid[currentRow-1][currentCol] = 2;
                    freshOrangesCnt--;
                    q.push({currentRow-1, currentCol});
                }
                if(currentRow + 1 < grid.size() && grid[currentRow+1][currentCol] == 1)
                {
                    grid[currentRow+1][currentCol] = 2;
                    freshOrangesCnt--;
                    q.push({currentRow+1, currentCol});
                }
                if(currentCol - 1 >= 0 && grid[currentRow][currentCol-1] == 1)
                {
                    grid[currentRow][currentCol - 1] = 2;
                    freshOrangesCnt--;
                    q.push({currentRow, currentCol - 1});
                }
                if(currentCol + 1 < grid[0].size() && grid[currentRow][currentCol+1] == 1)
                {
                    grid[currentRow][currentCol + 1] = 2;
                    freshOrangesCnt--;
                    q.push({currentRow, currentCol+1});
                }
                size--;
                q.pop();
            }
        }
        if(freshOrangesCnt > 0)
            return -1;
        else
            return minutes;
    }
};
```
