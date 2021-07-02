# Leetcode 118 Pascal's Triangle

## Problem Statement

[https://leetcode.com/problems/pascals-triangle/](https://leetcode.com/problems/pascals-triangle/)

Given an integer `numRows`, return the first numRows of **Pascal's triangle**.

In **Pascal's triangle**, each number is the sum of the two numbers directly above it as shown: ![](https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif)

**Example 1:**

```text
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
```

**Example 2:**

```text
Input: numRows = 1
Output: [[1]]
```

**Constraints:**

* `1 <= numRows <= 30`

## Solution

```cpp
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        result[0] = {1};
        for(int i = 1; i < numRows; i++)
        {
            result[i].push_back(result[i-1][0]);
            for(int j = 1; j < i; j++) // i-1 will have "i" elements in pascal
                result[i].push_back(result[i-1][j-1] + result[i-1][j]);
            result[i].push_back(result[i-1][i-1]);
        }
        return result;
    }
};
```

