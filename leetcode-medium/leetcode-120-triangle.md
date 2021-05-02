# Leetcode 120 Triangle

## Problem Statement

[https://leetcode.com/problems/triangle/](https://leetcode.com/problems/triangle/)

Given a `triangle` array, return _the minimum path sum from top to bottom_.

For each step, you may move to an adjacent number of the row below. More formally, if you are on index `i` on the current row, you may move to either index `i` or index `i + 1` on the next row.

**Example 1:**

```text
Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
Output: 11
Explanation: The triangle looks like:
   2
  3 4
 6 5 7
4 1 8 3
The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
```

**Example 2:**

```text
Input: triangle = [[-10]]
Output: -10
```

**Constraints:**

* `1 <= triangle.length <= 200`
* `triangle[0].length == 1`
* `triangle[i].length == triangle[i - 1].length + 1`
* `-10^4 <= triangle[i][j] <= 10^4`

  **Follow up:** Could you do this using only `O(n)` extra space, where `n` is the total number of rows in the triangle?

## Solution

```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> memo(triangle.size()+1, 0);
        
        for(int i = triangle.size() - 1; i >=0; i--)
            for(int j = 0; j < triangle[i].size(); j++)
                memo[j] = triangle[i][j] + min(memo[j], memo[j+1]);
        
        return memo[0];
    }
};
```

