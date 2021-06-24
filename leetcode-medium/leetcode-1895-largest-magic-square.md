# Leetcode 1895 Largest Magic Square

## Problem Statement

[https://leetcode.com/problems/largest-magic-square/](https://leetcode.com/problems/largest-magic-square/)

A `k x k` **magic square** is a `k x k` grid filled with integers such that every row sum, every column sum, and both diagonal sums are **all equal**. The integers in the magic square **do not have to be distinct**. Every `1 x 1` grid is trivially a **magic square**.

Given an `m x n` integer `grid`, return _the **size** \(i.e., the side length_ `k`_\) of the **largest magic square** that can be found within this grid_.

**Example 1:** ![](https://assets.leetcode.com/uploads/2021/05/29/magicsquare-grid.jpg)

```text
Input: grid = [[7,1,4,5,6],[2,5,1,6,4],[1,5,4,3,2],[1,2,7,3,4]]
Output: 3
Explanation: The largest magic square has a size of 3.
Every row sum, column sum, and diagonal sum of this magic square is equal to 12.
- Row sums: 5+1+6 = 5+4+3 = 2+7+3 = 12
- Column sums: 5+5+2 = 1+4+7 = 6+3+3 = 12
- Diagonal sums: 5+4+3 = 6+4+2 = 12
```

**Example 2:** ![](https://assets.leetcode.com/uploads/2021/05/29/magicsquare2-grid.jpg)

```text
Input: grid = [[5,1,3,1],[9,3,3,1],[1,3,3,8]]
Output: 2
```

**Constraints:**

* `m == grid.length`
* `n == grid[i].length`
* `1 <= m, n <= 50`
* `1 <= grid[i][j] <= 10^6`

## Solution

```cpp
class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int result = 1;
        int sq_size = min(m,n);
        vector<vector<long>> rowSum(m, vector<long>(n+1,0));
        vector<vector<long>> colSum(m+1, vector<long>(n,0));
        
        // Pre-calculate Row and Col sum
        for(int i = 0; i < m; i++){
            for(int j = 1; j <= n; j++){
                rowSum[i][j] = rowSum[i][j-1] + grid[i][j-1];
            }
        }
        for(int j = 0; j < n; j++){
            for(int i = 1; i <= m; i++){
                colSum[i][j] = colSum[i-1][j] + grid[i-1][j];
            }
        }
        
        while(sq_size > 1)
        {
            for(int i = 0; i+sq_size <= m; i++)
            {
                for(int j = 0; j+sq_size <= n; j++)
                {
                    bool flag = true;
                    long res = rowSum[i][j+sq_size] - rowSum[i][j];
                    
                    for(int x = i; x < i+sq_size; x++)
                    {
                        if(rowSum[x][j+sq_size] - rowSum[x][j] != res)
                        {
                            flag = false;
                            break;
                        }
                    }
                    if(!flag)
                        continue;
                        
                    for(int x = j; x < j+sq_size; x++)
                    {
                        if(colSum[i+sq_size][x] - colSum[i][x] != res)
                        {
                            flag = false;
                            break;
                        }
                    }
                    if(!flag)
                        continue;
                        
                    // diagonal and antidiagonal sum
                    int dia_total = 0, anti_dia_total = 0;
                    for(int row = i; row < sq_size+i; row++)
                    { 
                        for(int col = j; col < sq_size+j; col++)
                        {
                            if(col - row == j-i)  
                                dia_total += grid[row][col];
                            if(col + row == sq_size - 1 + i + j) 
                                anti_dia_total += grid[row][col];
                        }
                    }
                    if(dia_total == res && anti_dia_total == res)
                        return sq_size;    
                }
            }
            sq_size--;
        }
        return sq_size;
    }
};
```

