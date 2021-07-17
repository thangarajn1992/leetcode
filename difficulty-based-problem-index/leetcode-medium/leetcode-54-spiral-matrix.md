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
        vector<int> spiral_order;
        vector<vector<int>> dir = {{0,1}, {1, 0}, {0,-1}, {-1,0}};
        int count = rows * cols;
        int cur_r = 0, cur_c = 0, cur_dir = 0;
        vector<vector<bool>> visited(rows, vector<bool>(cols,false));
        while(count > 0)
        {
            spiral_order.push_back(matrix[cur_r][cur_c]);
            visited[cur_r][cur_c] = true;
            int next_r = cur_r + dir[cur_dir][0];
            int next_c = cur_c + dir[cur_dir][1];
            if(next_r < 0 || next_r >= rows ||
               next_c < 0 || next_c >= cols ||
               visited[next_r][next_c] == true) // change the direction
            {
                cur_dir = (cur_dir + 1) % 4;
                next_r = cur_r + dir[cur_dir][0];
                next_c = cur_c + dir[cur_dir][1];
            }
            cur_r = next_r;
            cur_c = next_c; 
            count--;
        }
        return spiral_order;        
    }
};
```

