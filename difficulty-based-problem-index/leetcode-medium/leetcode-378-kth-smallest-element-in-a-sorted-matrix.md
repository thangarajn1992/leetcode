# Leetcode 378 Kth Smallest Element in a Sorted Matrix

## Problem Statement

[https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/)

Given an `n x n` `matrix` where each of the rows and columns are sorted in ascending order, return _the_ `kth` _smallest element in the matrix_.

Note that it is the `kth` smallest element **in the sorted order**, not the `kth` **distinct** element.

**Example 1:**

```text
Input: matrix = [[1,5,9],[10,11,13],[12,13,15]], k = 8
Output: 13
Explanation: 
The elements in the matrix are [1,5,9,10,11,12,13,13,15],and the 8th smallest number is 13
```

**Example 2:**

```text
Input: matrix = [[-5]], k = 1
Output: -5
```

**Constraints:**

* `n == matrix.length`
* `n == matrix[i].length`
* `1 <= n <= 300`
* `-10^9 <= matrix[i][j] <= 10^9`
* All the rows and columns of `matrix` are **guaranteed** to be sorted in **non-decreasing order**.
* `1 <= k <= n^2`

## Solution

### Binary Search Approach

```cpp
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();

        int left = matrix[0][0], right = matrix[n-1][n-1], mid;
        while(left <= right)
        {
            mid =  (right + left)/2;
            int count = 0;  // count is the no of ele less than mid in the matrix                  
       
            for(int i = 0; i < n; i++)
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
                      
            if(count < k)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
};
```

