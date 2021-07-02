# Leetcode 1905 Count Sub Islands

## Problem Statement

[https://leetcode.com/problems/count-sub-islands/](https://leetcode.com/problems/count-sub-islands/)

You are given two `m x n` binary matrices `grid1` and `grid2` containing only `0`'s \(representing water\) and `1`'s \(representing land\). An **island** is a group of `1`'s connected **4-directionally** \(horizontal or vertical\). Any cells outside of the grid are considered water cells.

An island in `grid2` is considered a **sub-island** if there is an island in `grid1` that contains **all** the cells that make up **this** island in `grid2`.

Return the _**number** of islands in_ `grid2` _that are considered **sub-islands**_.

**Example 1:** ![](https://assets.leetcode.com/uploads/2021/06/10/test1.png)

```text
Input: grid1 = [[1,1,1,0,0],[0,1,1,1,1],[0,0,0,0,0],[1,0,0,0,0],[1,1,0,1,1]], grid2 = [[1,1,1,0,0],[0,0,1,1,1],[0,1,0,0,0],[1,0,1,1,0],[0,1,0,1,0]]
Output: 3
Explanation: 
In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. 
There are three sub-islands.
```

**Example 2:** ![](https://assets.leetcode.com/uploads/2021/06/03/testcasex2.png)

```text
Input: grid1 = [[1,0,1,0,1],[1,1,1,1,1],[0,0,0,0,0],[1,1,1,1,1],[1,0,1,0,1]], grid2 = [[0,0,0,0,0],[1,1,1,1,1],[0,1,0,1,0],[0,1,0,1,0],[1,0,0,0,1]]
Output: 2 
Explanation: 
In the picture above, the grid on the left is grid1 and the grid on the right is grid2.
The 1s colored red in grid2 are those considered to be part of a sub-island. 
There are two sub-islands.
```

**Constraints:**

* `m == grid1.length == grid2.length`
* `n == grid1[i].length == grid2[i].length`
* `1 <= m, n <= 500`
* `grid1[i][j]` and `grid2[i][j]` are either `0` or `1`.

## Solution

### My Approach : Drown Grid2 Island if Water is present in Grid1

```cpp
class Solution {
public:
    vector<vector<int>> dir = {{-1,0}, {1, 0}, {0, 1}, {0, -1}};
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int result;
        for(int row = 0; row < grid2.size(); row++)
        {
            for(int col = 0; col < grid2[0].size(); col++)
            {
                if(grid2[row][col] == 1)
                {
                    bool submerged = false;
                    stack<pair<int,int>> s;
                    s.push(make_pair(row,col));
                    grid2[row][col] = 0;
                    if(grid1[row][col] == 0)
                        submerged = true;
                    while(!s.empty())
                    {
                        auto e = s.top();
                        s.pop();
                        for(int d = 0; d < dir.size(); d++)
                        {
                            int r = e.first + dir[d][0];
                            int c = e.second + dir[d][1];
                            if( r >= 0 && r < grid2.size() &&
                                c >= 0 && c < grid2[0].size() &&
                                grid2[r][c] == 1)
                            {
                                s.push(make_pair(r,c));
                                if(grid1[r][c] == 0)
                                    submerged = true;
                                grid2[r][c] = 0;
                            }
                        }
                    }
                    if(!submerged)
                        result++;
                }
            }
        }
        return result;
    }
};
```

