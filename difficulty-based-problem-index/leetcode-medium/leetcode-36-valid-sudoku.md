# Leetcode 36 Valid Sudoku

## Problem Statement

[https://leetcode.com/problems/valid-sudoku/](https://leetcode.com/problems/valid-sudoku/)

Determine if a `9 x 9` Sudoku board is valid. Only the filled cells need to be validated **according to the following rules**:

1. Each row must contain the digits `1-9` without repetition.
2. Each column must contain the digits `1-9` without repetition.
3. Each of the nine `3 x 3` sub-boxes of the grid must contain the digits `1-9` without repetition.

**Note:**

* A Sudoku board \(partially filled\) could be valid but is not necessarily solvable.
* Only the filled cells need to be validated according to the mentioned rules.

**Example 1:** ![](https://upload.wikimedia.org/wikipedia/commons/thumb/f/ff/Sudoku-by-L2G-20050714.svg/250px-Sudoku-by-L2G-20050714.svg.png)

```text
Input: board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: true
```

**Example 2:**

```text
Input: board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
Output: false
Explanation: 
Same as Example 1, except with the 5 in the top left corner being modified
to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
```

**Constraints:**

* `board.length == 9`
* `board[i].length == 9`
* `board[i][j]` is a digit or `'.'`.

## Solution

### Using bool array

```cpp
#define BOARD_SIZE 9
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rows[BOARD_SIZE][BOARD_SIZE] = {false};
        bool cols[BOARD_SIZE][BOARD_SIZE] = {false};
        bool boxs[BOARD_SIZE][BOARD_SIZE] = {false};
        for(int row = 0; row < BOARD_SIZE; row++)
            for(int col = 0; col < BOARD_SIZE; col++)
                if(board[row][col] != '.') {  
                    int num = board[row][col] - '1';  
                    int box = (row / 3) * 3 + col / 3;
                    if(rows[row][num] || cols[col][num] || boxs[box][num]) 
                        return false;
                    rows[row][num] = cols[col][num] = boxs[box][num] = true;
                }
        return true;
    }
};
```

### Using maps

```cpp
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<int, map<char,int>> rows;
        map<int, map<char,int>> cols;
        map<int, map<char,int>> boxs;
        for(int i = 0; i < board.size(); i++)
            for(int j = 0; j < board[i].size(); j++)
            {
                if(board[i][j] =='.')
                    continue;
                int box = (i/3)*3 + (j/3);
                rows[i][board[i][j]]++;
                cols[j][board[i][j]]++;
                boxs[box][board[i][j]]++;
                if(rows[i][board[i][j]] > 1 || cols[j][board[i][j]] > 1 ||
                   boxs[box][board[i][j]] > 1)
                    return false;    
            }
        return true;       
    }
};
```

### Using 2-D vector + bitmask

```cpp
class Solution {
public: 
   bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> m(3, vector<int>(9,0));
        for(int i = 0; i < 9; i++)
            for(int j = 0; j < 9; j++)
            {
                if(board[i][j] == '.')
                    continue;
                int mask = 1 << (board[i][j] - '1');
                int box = (i/3)*3 + (j/3);
                
                if(m[0][i] & mask || m[1][j] & mask || m[2][box] & mask)
                    return false;
                    
                m[0][i] |= mask;
                m[1][j] |= mask;
                m[2][box] |= mask;
            }
        return true;
    }
};
    
```

