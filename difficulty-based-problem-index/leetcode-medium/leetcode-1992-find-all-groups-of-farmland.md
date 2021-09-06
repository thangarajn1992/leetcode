# Leetcode 1992 Find All Groups of Farmland

## Problem Statement

[https://leetcode.com/problems/find-all-groups-of-farmland/](https://leetcode.com/problems/find-all-groups-of-farmland/)

You are given a **0-indexed** `m x n` binary matrix `land` where a `0` represents a hectare of forested land and a `1` represents a hectare of farmland.

To keep the land organized, there are designated rectangular areas of hectares that consist **entirely** of farmland. These rectangular areas are called **groups**. No two groups are adjacent, meaning farmland in one group is **not** four-directionally adjacent to another farmland in a different group.

`land` can be represented by a coordinate system where the top left corner of `land` is `(0, 0)` and the bottom right corner of `land` is `(m-1, n-1)`. Find the coordinates of the top left and bottom right corner of each **group** of farmland. A **group** of farmland with a top left corner at `(r1, c1)` and a bottom right corner at `(r2, c2)` is represented by the 4-length array `[r1, c1, r2, c2].`

Return _a 2D array containing the 4-length arrays described above for each **group** of farmland in_ `land`_. If there are no groups of farmland, return an empty array. You may return the answer in **any order**_.

**Example 1:** ![](https://assets.leetcode.com/uploads/2021/07/27/screenshot-2021-07-27-at-12-23-15-copy-of-diagram-drawio-diagrams-net.png)

```text
Input: land = [[1,0,0],[0,1,1],[0,1,1]]
Output: [[0,0,0,0],[1,1,2,2]]
Explanation:
The first group has a top left corner at land[0][0] and a bottom right corner at land[0][0].
The second group has a top left corner at land[1][1] and a bottom right corner at land[2][2].
```

**Example 2:** ![](https://assets.leetcode.com/uploads/2021/07/27/screenshot-2021-07-27-at-12-30-26-copy-of-diagram-drawio-diagrams-net.png)

```text
Input: land = [[1,1],[1,1]]
Output: [[0,0,1,1]]
Explanation:
The first group has a top left corner at land[0][0] and a bottom right corner at land[1][1].
```

**Example 3:** ![](https://assets.leetcode.com/uploads/2021/07/27/screenshot-2021-07-27-at-12-32-24-copy-of-diagram-drawio-diagrams-net.png)

```text
Input: land = [[0]]
Output: []
Explanation:
There are no groups of farmland.
```

**Constraints:**

* `m == land.length`
* `n == land[i].length`
* `1 <= m, n <= 300`
* `land` consists of only `0`'s and `1`'s.
* Groups of farmland are **rectangular** in shape.

## Solution

### My Own Solution - Rectangle Tracing + flooding 100% faster

```cpp
class Solution {
public:
    vector<vector<int>> farmGroups;
    int totalRows, totalCols;
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        totalRows = land.size();
        totalCols = land[0].size();
        
        for(int rowNum = 0; rowNum < totalRows; rowNum++)
            for(int colNum = 0; colNum < totalCols; colNum++)
                if(land[rowNum][colNum] == 1)
                    findGroup(land, rowNum, colNum, rowNum, colNum);
    
        return farmGroups;
    }
    
    void findGroup(vector<vector<int>>&land, int startRow, int startCol, 
                   int currentRow, int currentCol)
    {
        // check if we can move right and that has 1
        if(currentCol + 1 < totalCols && land[currentRow][currentCol+1] == 1)
        {
            findGroup(land, startRow, startCol, currentRow, currentCol+1);
        }
        else if(currentRow+1 < totalRows)
            // move down and complete the rectange
        {
            if(land[currentRow+1][currentCol] == 1)
                findGroup(land, startRow, startCol, currentRow+1, currentCol);
            else // rectangle is done, reset all its entry to 0
            {
                farmGroups.push_back({startRow, startCol, currentRow, currentCol});
                for(int rowNum = startRow; rowNum <= currentRow; rowNum++)
                    for(int colNum = startCol; colNum <= currentCol; colNum++)
                        land[rowNum][colNum] = 0;
            }
        }
        else // rectangle is done, reset all its entry to 0
        {
            farmGroups.push_back({startRow, startCol, currentRow, currentCol});
            for(int rowNum = startRow; rowNum <= currentRow; rowNum++)
                for(int colNum = startCol; colNum <= currentCol; colNum++)
                    land[rowNum][colNum] = 0;
        }
    }
};
```

