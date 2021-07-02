# Leetcode 79 Word Search

## Problem Statement

[https://leetcode.com/problems/word-search/](https://leetcode.com/problems/word-search/)

Given an `m x n` grid of characters `board` and a string `word`, return `true` _if_ `word` _exists in the grid_.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

**Example 1:** ![](https://assets.leetcode.com/uploads/2020/11/04/word2.jpg)

```text
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
```

**Example 2:** ![](https://assets.leetcode.com/uploads/2020/11/04/word-1.jpg)

```text
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
```

**Example 3:** ![](https://assets.leetcode.com/uploads/2020/10/15/word3.jpg)

```text
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
```

**Constraints:**

* `m == board.length`
* `n = board[i].length`
* `1 <= m, n <= 6`
* `1 <= word.length <= 15`
* `board` and `word` consists of only lowercase and uppercase English letters.

**Follow up:** Could you use search pruning to make your solution faster with a larger `board`?

## Solution

```cpp
class Solution {
public:
    vector<vector<bool>> visited;
    vector<vector<int>> dir;
    
    bool exist(vector<vector<char>>& board, string word) {
        /* Check whether we have needed characters in board */
        vector<int> v1(128,0);
        vector<int> v2(128,0);
        for(char c: word)
            v1[c]++;
        for(auto ar : board)
            for(auto c : ar)
                v2[c]++;
        for(int i = 0; i < 128; i++)
            if(v1[i] > v2[i])
                return false;
        
        /*Check whether we have needed characters in correct order */
        visited.resize(board.size(), vector<bool>(board[0].size(), false));
        dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
        for(int row = 0; row < board.size(); row++)
        {
            for(int col = 0; col < board[0].size(); col++)
            {
                if(board[row][col] == word[0])
                {
                    visited[row][col] = true;
                    if(search_next(board, word, 1, row, col))
                        return true;
                    visited[row][col] = false;
                }
            }
        }
        return false;
    }
    bool search_next(vector<vector<char>>&board, string word, int index, int r, int c)
    {
        if(index == word.size())
            return true;
        
        for(int i = 0; i < dir.size(); i++)
        {
            int cur_r = r + dir[i][0];
            int cur_c = c + dir[i][1];
            if(cur_r >= 0 && cur_r < board.size() &&
               cur_c >= 0 && cur_c < board[0].size() &&
               !visited[cur_r][cur_c] && board[cur_r][cur_c] == word[index])
            {
                visited[cur_r][cur_c] = true;
                if(search_next(board, word, index+1, cur_r, cur_c))
                    return true;
                visited[cur_r][cur_c] = false;
            }
        }
        return false;
    }
};
```

