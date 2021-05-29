# Leetcode 52  N-Queens II

## Problem Statement

[https://leetcode.com/problems/n-queens-ii/](https://leetcode.com/problems/n-queens-ii/)

The **n-queens** puzzle is the problem of placing `n` queens on an `n x n` chessboard such that no two queens attack each other.

Given an integer `n`, return _the number of distinct solutions to the **n-queens puzzle**_.

**Example 1:** ![](https://assets.leetcode.com/uploads/2020/11/13/queens.jpg)

```text
Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.
```

**Example 2:**

```text
Input: n = 1
Output: 1
```

**Constraints:**

* `1 <= n <= 9`

## Solution

```cpp
class Solution {
public:
    int size;
    int combinations;
    vector<bool> cols;
    vector<bool> diagonals;
    vector<bool> antidiagonals;

    void backtrack(int row)
    {
        if(row >= size) // end-case
        {
            combinations++;
            return;
        }
        
        for(int col = 0; col < size; col++)
        {
            int currDiagonal = (row - col) + size - 1;
            int currAntiDiagonal = row + col;
            
            // Can we place queen here ?
            if( !cols[col] && !diagonals[currDiagonal] &&
                !antidiagonals[currAntiDiagonal])
            {            
            // "Add" the queen to the board
            cols[col] = true;
            diagonals[currDiagonal] = true;
            antidiagonals[currAntiDiagonal] = true;
            
            // Move to next row with updated board state
            backtrack(row+1);
            
            // "Remove this queen from board and check for other possiblities"
            cols[col] = false;
            diagonals[currDiagonal] = false;
            antidiagonals[currAntiDiagonal] = false;
            }
        }
    }
    
    int totalNQueens(int n) {
        size = n;
        cols.resize(n,false);
        diagonals.resize(2*n - 1, false); 
        antidiagonals.resize(2*n - 1, false);
        backtrack(0);
        return combinations;
    }
};
```

