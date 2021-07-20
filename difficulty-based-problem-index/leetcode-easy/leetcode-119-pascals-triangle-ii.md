# Leetcode 119 Pascal's Triangle II

## Problem Statement

[https://leetcode.com/problems/pascals-triangle-ii/](https://leetcode.com/problems/pascals-triangle-ii/)

Given an integer `rowIndex`, return the `rowIndexth` \(**0-indexed**\) row of the **Pascal's triangle**.

In **Pascal's triangle**, each number is the sum of the two numbers directly above it as shown: ![](https://upload.wikimedia.org/wikipedia/commons/0/0d/PascalTriangleAnimated2.gif)

**Example 1:**

```text
Input: rowIndex = 3
Output: [1,3,3,1]
```

**Example 2:**

```text
Input: rowIndex = 0
Output: [1]
```

**Example 3:**

```text
Input: rowIndex = 1
Output: [1,1]
```

**Constraints:**

* `0 <= rowIndex <= 33`

**Follow up:** Could you optimize your algorithm to use only `O(rowIndex)` extra space?

## Solution

```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> result(rowIndex+1);
        result[0] = {1};
        for(int i = 1; i <= rowIndex; i++)
        {
            result[i].push_back(result[i-1][0]);
            for(int j = 1; j < i; j++) // i-1 will have "i" elements in pascal
                result[i].push_back(result[i-1][j-1] + result[i-1][j]);
            result[i].push_back(result[i-1][i-1]);
        }
        return result.back();
    }
};
```

