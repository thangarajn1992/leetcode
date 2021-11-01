# Leetcode 130 Surrounded Regions

## Problem Statement

[https://leetcode.com/problems/surrounded-regions/](https://leetcode.com/problems/surrounded-regions/)

Given an `m x n` matrix `board` containing `'X'` and `'O'`, _capture all regions that are 4-directionally surrounded by_ `'X'`.

A region is **captured** by flipping all `'O'`s into `'X'`s in that surrounded region.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/02/19/xogrid.jpg)

```
Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation: 
Surrounded regions should not be on the border, which means that any 'O' 
on the border of the board are not flipped to 'X'. 
Any 'O' that is not on the border and it is not connected to an 'O' 
on the border will be flipped to 'X'. 
Two cells are connected if they are adjacent cells connected horizontally or vertically.
```

**Example 2:**

```
Input: board = [["X"]]
Output: [["X"]]
```

&#x20;

**Constraints:**

* `m == board.length`
* `n == board[i].length`
* `1 <= m, n <= 200`
* `board[i][j]` is `'X'` or `'O'`.

## Solution

### Algorithm

We will use boundary DFS to solve this problem

Lets analyze when an 'O' cannot be flipped, if it has atleast one '0' in its adjacent, and ultimately this chain of adjacent 'O's is connected to some 'O' which lies on boundary of board.

Consider these two cases for clarity:

```
    O's won't be flipped          O's will be flipped
    [X O X X X]                   [X X X X X]     
    [X O O O X]                   [X O O O X]
    [X O X X X]                   [X O X X X] 
    [X X X X X]                   [X X X X X]
```

Steps to Solve :

1. Move over the boundary of board, and find O's
2. Every time we find an O, perform DFS from its position
3. In DFS convert all '0' to '#' indicating that this '0' cannot be converted to 'X'.
4. After all DFS have been performed, board will contains three different elements, 'X' , 'O', '#'.
5. 'O' are left over elements which can be converted to 'X'.&#x20;
6. '#' are the elements that cannot be converted to 'X'.
7. Traverse over all elements and convert '0' into 'X', and '#' into 'O'.

```cpp
class Solution {
public:
    int rows, cols;
    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();
        
        // find first and last col entries with 'O'
        for(int row = 0; row < rows; row++)
        {
            if(board[row][0] == 'O')
                boundaryDFS(row, 0, board);
            if(board[row][cols-1] == 'O')
                boundaryDFS(row, cols-1, board);
        }
        
        // find first and last row entries with 'O'
        for(int col = 0; col < cols; col++)
        {
            if(board[0][col] == 'O')
                boundaryDFS(0, col, board);
            if(board[rows-1][col] == 'O')
                boundaryDFS(rows-1, col, board);
        }
        
        
        // Replace all 'O' with 'X' and all '#' with 'O'
        for(int row = 0; row < rows; row++)
        {
            for(int col = 0; col < cols; col++)
            {
                if(board[row][col] == 'O')
                    board[row][col] = 'X';
                if(board[row][col] == '#')
                    board[row][col] = 'O';
            }
        }
    }
    
    void boundaryDFS(int row, int col, vector<vector<char>>& board)
    {
        if(row < 0 || row >= rows || col < 0 || col >= cols ||
           board[row][col] != 'O')
            return;
        
        board[row][col] = '#';
        boundaryDFS(row+1, col, board);
        boundaryDFS(row-1, col, board);
        boundaryDFS(row, col+1, board);
        boundaryDFS(row, col-1, board);
    }
};
```
