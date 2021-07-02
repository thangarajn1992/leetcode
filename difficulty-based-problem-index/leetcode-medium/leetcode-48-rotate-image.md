# Leetcode 48 Rotate Image

## Problem Statement

[https://leetcode.com/problems/rotate-image/](https://leetcode.com/problems/rotate-image/)

You are given an _n_ x _n_ 2D `matrix` representing an image, rotate the image by 90 degrees \(clockwise\).

You have to rotate the image [**in-place**](https://en.wikipedia.org/wiki/In-place_algorithm), which means you have to modify the input 2D matrix directly. **DO NOT** allocate another 2D matrix and do the rotation.

**Example 1:** ![](https://assets.leetcode.com/uploads/2020/08/28/mat1.jpg)

```text
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]
```

**Example 2:** ![](https://assets.leetcode.com/uploads/2020/08/28/mat2.jpg)

```text
Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]
```

**Example 3:**

```text
Input: matrix = [[1]]
Output: [[1]]
```

**Example 4:**

```text
Input: matrix = [[1,2],[3,4]]
Output: [[3,1],[4,2]]
```

**Constraints:**

* `matrix.length == n`
* `matrix[i].length == n`
* `1 <= n <= 20`
* `-1000 <= matrix[i][j] <= 1000`

## Solution

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n == 1)
            return;
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
                swap(matrix[i][j], matrix[j][i]);
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
```

