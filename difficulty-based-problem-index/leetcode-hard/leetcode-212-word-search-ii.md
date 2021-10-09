# Leetcode 212 Word Search II

## Problem Statement

[https://leetcode.com/problems/word-search-ii/](https://leetcode.com/problems/word-search-ii/)

Given an `m x n` `board` of characters and a list of strings `words`, return _all words on the board_.

Each word must be constructed from letters of sequentially adjacent cells, where **adjacent cells** are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

**Example 1:** ![](https://assets.leetcode.com/uploads/2020/11/07/search1.jpg)

```text
Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
Output: ["eat","oath"]
```

**Example 2:** ![](https://assets.leetcode.com/uploads/2020/11/07/search2.jpg)

```text
Input: board = [["a","b"],["c","d"]], words = ["abcb"]
Output: []
```

**Constraints:**

* `m == board.length`
* `n == board[i].length`
* `1 <= m, n <= 12`
* `board[i][j]` is a lowercase English letter.
* `1 <= words.length <= 3 * 10^4`
* `1 <= words[i].length <= 10`
* `words[i]` consists of lowercase English letters.
* All the strings of `words` are unique.

## Solution

```cpp
class Solution {
public:
    vector<vector<int>> dir = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> foundWords;
        /* Check whether we have needed characters in board */
        vector<int> boardFreq(128,0);
        
        for(vector<char> row : board)
            for(char c : row)
                boardFreq[c]++;
        for(string word : words)
        {
            vector<int> wordFreq(128,0);
            for(char c: word)
                wordFreq[c]++;
            
            int index = 0;
            for(; index < 128; index++)
                if(wordFreq[index] > boardFreq[index])
                    break;
            
            if(index == 128 && exist(board, word) == true)
                foundWords.push_back(word);
        }
        return foundWords;
    }
        
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        /*Check whether we have needed characters in correct order */
        
        for(int row = 0; row < board.size(); row++)
        {
            for(int col = 0; col < board[0].size(); col++)
            {
                if(board[row][col] == word[0])
                {
                    visited[row][col] = true;
                    if(search_next(board, word, 1, row, col, visited))
                        return true;
                    visited[row][col] = false;
                }
            }
        }
        return false;
    }
    
    bool search_next(vector<vector<char>>&board, string word, int index, int r, int c,
                     vector<vector<bool>> &visited)
    {
        if(index == word.size())
            return true;
        
        for(int d = 0; d < dir.size(); d++)
        {
            int cur_r = r + dir[d][0];
            int cur_c = c + dir[d][1];
            if(cur_r >= 0 && cur_r < board.size() &&
               cur_c >= 0 && cur_c < board[0].size() &&
               !visited[cur_r][cur_c] && board[cur_r][cur_c] == word[index])
            {
                visited[cur_r][cur_c] = true;
                if(search_next(board, word, index+1, cur_r, cur_c, visited))
                    return true;
                visited[cur_r][cur_c] = false;
            }
        }
        return false;
    }
};
```

