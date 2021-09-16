# Leetcode 54 Spiral Matrix

## Problem Statement

[https://leetcode.com/problems/spiral-matrix/](https://leetcode.com/problems/spiral-matrix/)

Given an `m x n` `matrix`, return _all elements of the_ `matrix` _in spiral order_.

**Example 1:** ![](https://assets.leetcode.com/uploads/2020/11/13/spiral1.jpg)

```text
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]
```

**Example 2:** ![](https://assets.leetcode.com/uploads/2020/11/13/spiral.jpg)

```text
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
```

**Constraints:**

* `m == matrix.length`
* `n == matrix[i].length`
* `1 <= m, n <= 10`
* `-100 <= matrix[i][j] <= 100`

## Solution

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> spiralOrderResult;
        vector<vector<int>> dir = {{0,1}, {1, 0}, {0,-1}, {-1,0}};
        int count = rows * cols;
        int curRow = 0, curCol = 0, curDir = 0;
        vector<vector<bool>> visited(rows, vector<bool>(cols,false));
        while(count > 0)
        {
            spiralOrderResult.push_back(matrix[curRow][curCol]);
            visited[curRow][curCol] = true;
            int nextRow = curRow + dir[curDir][0];
            int nextCol = curCol + dir[curDir][1];
            if(nextRow < 0 || nextRow >= rows ||
               nextCol < 0 || nextCol >= cols ||
               visited[nextRow][nextCol] == true) // change the direction
            {
                curDir = (curDir + 1) % 4;
                nextRow = curRow + dir[curDir][0];
                nextCol = curCol + dir[curDir][1];
            }
            curRow = nextRow;
            curCol = nextCol; 
            count--;
        }
        return spiralOrderResult;        
    }
};
```

