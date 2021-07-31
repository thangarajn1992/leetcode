# Leetcode 73 Set Matrix Zeroes

## Problem Statement

[https://leetcode.com/problems/set-matrix-zeroes/](https://leetcode.com/problems/set-matrix-zeroes/)

Given an _`m`_ `x` _`n`_ matrix. If an element is **0**, set its entire row and column to **0**. Do it [**in-place**](https://en.wikipedia.org/wiki/In-place_algorithm).

**Follow up:**

* A straight forward solution using O\(_mn_\) space is probably a bad idea.
* A simple improvement uses O\(_m_ + _n_\) space, but still not the best solution.
* Could you devise a constant space solution?

**Example 1:** ![](https://assets.leetcode.com/uploads/2020/08/17/mat1.jpg)

```text
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
```

**Example 2:** ![](https://assets.leetcode.com/uploads/2020/08/17/mat2.jpg)

```text
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
```

**Constraints:**

* `m == matrix.length`
* `n == matrix[0].length`
* `1 <= m, n <= 200`
* `-2^31 <= matrix[i][j] <= 2^31 - 1`

## Solution

```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> index;
        for(int row = 0; row < matrix.size(); row++)
            for(int col = 0; col < matrix[0].size(); col++)
                if(matrix[row][col] == 0)
                    index.push_back({row,col});
        for(auto e : index)
        {
            for(int col = 0; col < matrix[0].size(); col++)
                matrix[e.first][col] = 0;
            for(int row = 0; row < matrix.size(); row++)
                matrix[row][e.second] = 0;
        }
    }
};
```

