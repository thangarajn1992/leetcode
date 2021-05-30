# Leetcode 1878 Get Biggest Three Rhombus Sums in a Grid

## Problem Statement

[https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/](https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/)

You are given an `m x n` integer matrix `grid`​​​.

A **rhombus sum** is the sum of the elements that form **the** **border** of a regular rhombus shape in `grid`​​​. The rhombus must have the shape of a square rotated 45 degrees with each of the corners centered in a grid cell. Below is an image of four valid rhombus shapes with the corresponding colored cells that should be included in each **rhombus sum**: ![](https://assets.leetcode.com/uploads/2021/04/23/pc73-q4-desc-2.png)

Note that the rhombus can have an area of 0, which is depicted by the purple rhombus in the bottom right corner.

Return _the biggest three **distinct rhombus sums** in the_ `grid` _in **descending order**. If there are less than three distinct values, return all of them_.

**Example 1:** ![](https://assets.leetcode.com/uploads/2021/04/23/pc73-q4-ex1.png)

```text
Input: grid = [[3,4,5,1,3],[3,3,4,2,3],[20,30,200,40,10],[1,5,5,4,1],[4,3,2,2,5]]
Output: [228,216,211]
Explanation: 
The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
- Blue: 20 + 3 + 200 + 5 = 228
- Red: 200 + 2 + 10 + 4 = 216
- Green: 5 + 200 + 4 + 2 = 211
```

**Example 2:** ![](https://assets.leetcode.com/uploads/2021/04/23/pc73-q4-ex2.png)

```text
Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
Output: [20,9,8]
Explanation: 
The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
- Blue: 4 + 2 + 6 + 8 = 20
- Red: 9 (area 0 rhombus in the bottom right corner)
- Green: 8 (area 0 rhombus in the bottom middle)
```

**Example 3:**

```text
Input: grid = [[7,7,7]]
Output: [7]
Explanation: 
All three possible rhombus sums are the same, so return [7].
```

**Constraints:**

* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 50`
* `1 <= grid[i][j] <= 10^5`

## Solution

```cpp
class Solution {
public:
    int calc(vector<vector<int>>&grid, int row, int col, int side)
    {
        if(!side)
            return grid[row][col];
        int sum = 0;
        sum += grid[row][col] + grid[row + 2*side][col];
        for(int row_i = 1, col_i = 0; row_i < 2*side; row_i++)
        {
            if(row_i <= side)
                col_i = row_i;
            else 
                col_i = 2*side - row_i;
            sum += grid[row+row_i][col+col_i] + grid[row+row_i][col-col_i];
        }
        return sum;   
    }
    
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        vector<int> rhombus_sum;
        set<int> s;
        int m = grid.size();
        int n = grid[0].size();
        int max_side = min(m,n)/2;
        int side = 0;
        while(side <= max_side)
        {
            for(int row = 0; row + 2 *side < m; row++)
                for(int col = side; col + side < n; col++)
                {
                    s.insert(calc(grid, row, col, side));
                    if(s.size() > 3) s.erase(s.begin());
                }
            side++;
        }
        rhombus_sum.insert(rhombus_sum.begin(), s.rbegin(), s.rend());
        return rhombus_sum;
    }
};
```

