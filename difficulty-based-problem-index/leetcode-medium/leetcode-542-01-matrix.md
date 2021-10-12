# Leetcode 542 01 Matrix

## Problem Statement

[https://leetcode.com/problems/01-matrix/](https://leetcode.com/problems/01-matrix/)

Given an `m x n` binary matrix `mat`, return _the distance of the nearest_ `0` _for each cell_.

The distance between two adjacent cells is `1`.

**Example 1:** ![](https://assets.leetcode.com/uploads/2021/04/24/01-1-grid.jpg)

```
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
```

**Example 2:** ![](https://assets.leetcode.com/uploads/2021/04/24/01-2-grid.jpg)

```
Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]
```

**Constraints:**

* `m == mat.length`
* `n == mat[i].length`
* `1 <= m, n <= 10^4`
* `1 <= m * n <= 10^4`
* `mat[i][j]` is either `0` or `1`.
* There is at least one `0` in `mat`.

## Solution

### Breadth First Approach

Looking over the entire matrix appears wasteful and hence, we can use Breadth First Search (BFS) to limit the search to the nearest `0` found for each `1`. As soon as a `0` appears during the BFS, we know that the `0` is the closest, and hence, we move to the next `1`.

_Think again_: But, in this approach, we will only be able to update the distance of one `1` using one BFS, which could in fact, result in slightly higher complexity than the brute force approach. But hey, this could be optimized if we start the BFS from `0`s and thereby, updating the distances of all the `1`s in the path.

**Algorithm**

* For our BFS routine, we keep a queue, `q` to maintain the queue of cells to be examined next.
* We start by adding all the cells with `0`s to `q`.
* Initially, distance for each `0` cell is `0` and distance for each `1` is `INT_MAX`, which is updated during the BFS.
* Pop the cell from queue, and examine its neighbors. If the new calculated distance for neighbor `{i,j}` is smaller, we add `{i,j}` to `q` and update `dist[i][j]`.

**Complexity Analysis**

*   Time complexity: `O(r⋅c)`

    Since, the new cells are added to the queue only if their current distance is greater than the calculated distance, cells are not likely to be added multiple times.
*   Space complexity: `O(r⋅c)`

    An additional `O(r⋅c)` space is required to maintain the queue.

```cpp
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows == 0)
            return matrix;
        int cols = matrix[0].size();
        vector<vector<int>> dist(rows, vector<int> (cols, INT_MAX));
        queue<pair<int, int>> q;
        
        //Put all 0s in the queue.
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (matrix[row][col] == 0) {
                    dist[row][col] = 0;
                    q.push({ row, col }); 
                }
            }
        }

        int dir[4][2] = { { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };
        while (q.empty() == false) {
            pair<int, int> curr = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int new_r = curr.first + dir[d][0], new_c = curr.second + dir[d][1];
                if (new_r >= 0 && new_c >= 0 && new_r < rows && new_c < cols) {
                    if (dist[new_r][new_c] > dist[curr.first][curr.second] + 1) {
                        dist[new_r][new_c] = dist[curr.first][curr.second] + 1;
                        q.push({ new_r, new_c });
                    }
                }
            }
        }
        return dist;
    }
};
```

### Dynamic Programming Approach

**Intuition**

The distance of a cell from `0` can be calculated if we know the nearest distance for all the neighbors, in which case the distance is minimum distance of any neighbor + 1. And, instantly, the words come to mind Dynamic Programming (DP)!!\
For each `1`, the minimum path to `0` can be in any direction. So, we need to check all the 4 directions. In one iteration from top to bottom, we can check left and top directions, and we need another iteration from bottom to top to check for right and bottom direction.

**Algorithm**

* Iterate over the matrix from top to bottom-left to right:
  * Update `dist[i][j]= min(dist[i][j],min(dist[i][j−1],dist[i−1][j])+1)` i.e., minimum of the current dist and distance from top or left neighbor +1, that would have been already calculated previously in the current iteration.
* Now, we need to do the back iteration in the similar manner: from bottom to top-right to left:
  * Update `dist[i][j]=min(dist[i][j],min(dist[i][j+1],dist[i+1][j])+1)` i.e. minimum of current dist and distances calculated from bottom and right neighbors, that would be already available in current iteration.

**Complexity Analysis**

*   Time complexity: `O(r⋅c)`

    We perform two passes over the matrix and each pass requires `O(r⋅c)` time.
*   Space complexity: `O(1)`

    No extra space is required other than the space used to store the output (`dist`), and the output does not count towards the space complexity.

```cpp
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        if (rows == 0) 
            return matrix;
        int cols = matrix[0].size();
        vector<vector<int>> dist(rows, vector<int> (cols, INT_MAX - 100000));

        //First pass: check for left and top
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                if (matrix[row][col] == 0) {
                    dist[row][col] = 0;
                } else {
                    if (row > 0) // top
                        dist[row][col] = min(dist[row][col], dist[row - 1][col] + 1);
                    if (col > 0) // left
                        dist[row][col] = min(dist[row][col], dist[row][col - 1] + 1);
                }
            }
        }

        //Second pass: check for bottom and right
        for (int row = rows - 1; row >= 0; row--) {
            for (int col = cols - 1; col >= 0; col--) {
                if (row < rows - 1) // down
                    dist[row][col] = min(dist[row][col], dist[row + 1][col] + 1);
                if (col < cols - 1) // right
                    dist[row][col] = min(dist[row][col], dist[row][col + 1] + 1);
            }
        }
        return dist;
    }
};
```
