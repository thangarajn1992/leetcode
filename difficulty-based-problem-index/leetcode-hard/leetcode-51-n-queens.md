# Leetcode 51 N-Queens

## Problem Statement

[https://leetcode.com/problems/n-queens/](https://leetcode.com/problems/n-queens/)

The **n-queens** puzzle is the problem of placing `n` queens on an `n x n` chessboard such that no two queens attack each other.

Given an integer `n`, return _all distinct solutions to the **n-queens puzzle**_.

Each solution contains a distinct board configuration of the n-queens' placement, where `'Q'` and `'.'` both indicate a queen and an empty space, respectively.

**Example 1:** ![](https://assets.leetcode.com/uploads/2020/11/13/queens.jpg)

```text
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
```

**Example 2:**

```text
Input: n = 1
Output: [["Q"]]
```

**Constraints:**

* `1 <= n <= 9`

## Explanation

Given a board state, and a possible placement for a queen, we need a smart way to determine whether or not that placement will put the queen under attack. A queen can be attacked if another queen is on the same row, column, diagonal, or anti-diagonal.

Recall that to implement backtracking, we implement a `backtrack` function that makes some changes to the state, calls itself again, and then when that call returns it undoes those changes \(this last part is why it's called "backtracking"\).

Each time our `backtrack` function is called, we can encode the state in the following manner:

* To make sure that we only place 1 queen per **row**, we will pass an integer argument `row` into `backtrack`, and will only place one queen during each call. Whenever we place a queen, we'll move onto the next row by calling `backtrack` again with the parameter value `row + 1`.
* To make sure we only place 1 queen per **column**, we will use a set. Whenever we place a queen, we can add the column index to this set.

The diagonals are a little trickier - but they have a property that we can use to our advantage.

* For each square on a given **diagonal**, the difference between the row and column indices `(row - col)` will be constant. Think about the diagonal that starts from `(0, 0)` - theithi^{th}ith square has the coordinates `(i, i)`, so the difference is always 0.

![](https://leetcode.com/problems/n-queens/Figures/51/diagonals.png)

* For each square on a given **anti-diagonal**, the sum of the row and column indexes `(row + col)` will be constant. If you were to start at the highest square in an anti-diagonal and move downwards, the row index increments by 1 `(row + 1)`, and the column index decrements by 1 `(col - 1)`. These cancel each other out.

![](https://leetcode.com/problems/n-queens/Figures/51/antidiagonals.png)

Every time we place a queen, we should calculate the diagonal and the anti-diagonal value it belongs to. In the same way we use a set to keep track of which columns have been used, we should also have a set to keep track of which diagonals and anti-diagonals have been used. Then, we can add the values for this queen to the corresponding sets.

**Algorithm**

We'll create a recursive function `backtrack` that takes a few arguments to maintain the board state. The first parameter is the row we're going to place a queen on next, and then we will have 3 sets that track which columns, diagonals, and anti-diagonals have already had queens placed on them. Additionally, we will store the actual board so that when we find a valid solution, we can include it in our answer. The function will work as follows:

1. If the current row we are considering is equal to `n`, then we have a solution. Add the current board state to a list of solutions, and return. We'll make use of a small helper function to get our board into the correct output format.
2. Iterate through the columns of the current row. At each column, we will attempt to place a queen at the square `(row, col)` - remember we are considering the current row through the function arguments.
   * Calculate the diagonal and anti-diagonal that the square belongs to. If a queen has not been placed in the column, diagonal, or anti-diagonal, then we can place a queen in this column, in the current row.
   * If we can't place the queen, skip this column \(move on and try the next column\).
3. If we were able to place a queen, then add the queen to the board and update our 3 sets \(`cols`, `diagonals`, and `antiDiagonals`\), and call the function again, but with `row + 1`.
4. The function call made in step 3 explores all valid board states with the queen we placed in step 2. Since we're done exploring that path, backtrack by removing the queen from the square - this includes removing the values we added to our sets on top of removing the `"Q"` from the board.

## Solution

```cpp
class Solution {
public:
    int size;
    vector<vector<string>> combinations;
    vector<string> board_state;
    vector<bool> cols;
    vector<bool> diagonals;
    vector<bool> antidiagonals;

    void backtrack(int row)
    {
        if(row >= size) // end-case
        {
            combinations.push_back(board_state);
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
                board_state[row][col] = 'Q';
            
                // Move to next row with updated board state
                backtrack(row+1);
            
                // Remove this queen from board and check for other possiblities
                cols[col] = false;
                diagonals[currDiagonal] = false;
                antidiagonals[currAntiDiagonal] = false;
                board_state[row][col] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        size = n;
        board_state.resize(n, string(n,'.'));
        cols.resize(n,false);
        diagonals.resize(2*n - 1, false); 
        antidiagonals.resize(2*n - 1, false);
        backtrack(0);
        return combinations;
    }
};
```

