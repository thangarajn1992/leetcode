# Leetcode 764 Largest Plus Sign

## Problem Statement

[https://leetcode.com/problems/largest-plus-sign/](https://leetcode.com/problems/largest-plus-sign/)

You are given an integer `n`. You have an `n x n` binary grid `grid` with all values initially `1`'s except for some indices given in the array `mines`. The `ith` element of the array `mines` is defined as `mines[i] = [xi, yi]` where `grid[xi][yi] == 0`.

Return _the order of the largest **axis-aligned** plus sign of_ 1_'s contained in_ `grid`. If there is none, return `0`.

An **axis-aligned plus sign** of `1`'s of order `k` has some center `grid[r][c] == 1` along with four arms of length `k - 1` going up, down, left, and right, and made of `1`'s. Note that there could be `0`'s or `1`'s beyond the arms of the plus sign, only the relevant area of the plus sign is checked for `1`'s.

**Example 1:** ![](https://assets.leetcode.com/uploads/2021/06/13/plus1-grid.jpg)

```text
Input: n = 5, mines = [[4,2]]
Output: 2
Explanation: In the above grid, the largest plus sign can only be of order 2. 
One of them is shown.
```

**Example 2:** ![](https://assets.leetcode.com/uploads/2021/06/13/plus2-grid.jpg)

```text
Input: n = 1, mines = [[0,0]]
Output: 0
Explanation: There is no plus sign, so return 0.
```

**Constraints:**

* `1 <= n <= 500`
* `1 <= mines.length <= 5000`
* `0 <= xi, yi < n`
* All the pairs `(xi, yi)` are **unique**.

## Solution

```cpp
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> field(n, vector<int>(n,1));
        vector<vector<int>> leftOnes(n+2, vector<int>(n+2,0));
        vector<vector<int>> rightOnes(n+2, vector<int>(n+2,0));
        vector<vector<int>> upOnes(n+2, vector<int>(n+2,0));
        vector<vector<int>> downOnes(n+2, vector<int>(n+2,0));
        
        for(vector<int> &mine : mines)
            field[mine[0]][mine[1]] = 0;

        for(int row = 0; row < n; row++)
        {
            for(int col = 0; col < n; col++)
            {
                if(field[row][col] == 1)
                {
                    leftOnes[row+1][col+1] = leftOnes[row+1][col] + 1;
                    upOnes[row+1][col+1] = upOnes[row][col+1] + 1;
                }
            }
        }
        
        
        for(int row = n-1; row >= 0; row--)
        {
            for(int col = n-1; col >= 0; col--)
            {
                if(field[row][col] == 1)
                {
                    rightOnes[row+1][col+1] = rightOnes[row+1][col+2] + 1;
                    downOnes[row+1][col+1] = downOnes[row+2][col+1] + 1;
                }
            }
        }
        
        int largestAxisAlignedPlus = 0;
        for(int row = 0; row < n; row++)
            for(int col = 0; col < n; col++) 
                if(field[row][col] == 1)
                    largestAxisAlignedPlus = max(largestAxisAlignedPlus,
                                                 min(leftOnes[row+1][col+1], 
                                                     min(rightOnes[row+1][col+1], 
                                                         min(upOnes[row+1][col+1], downOnes[row+1][col+1]))));
        
        return largestAxisAlignedPlus;
        
    }
};
```

