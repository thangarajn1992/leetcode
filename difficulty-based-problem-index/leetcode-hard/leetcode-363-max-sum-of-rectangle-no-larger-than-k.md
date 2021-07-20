# Leetcode 363 Max Sum of Rectangle No Larger Than K

## Problem Statement

[https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/](https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/)

Given an `m x n` matrix `matrix` and an integer `k`, return _the max sum of a rectangle in the matrix such that its sum is no larger than_ `k`.

It is **guaranteed** that there will be a rectangle with a sum no larger than `k`.

**Example 1:** ![](https://assets.leetcode.com/uploads/2021/03/18/sum-grid.jpg)

```text
Input: matrix = [[1,0,1],[0,-2,3]], k = 2
Output: 2
Explanation: 
Because the sum of the blue rectangle [[0, 1], [-2, 3]] is 2, and 2 is the max number 
no larger than k (k = 2).
```

**Example 2:**

```text
Input: matrix = [[2,2,-1]], k = 3
Output: 3
```

**Constraints:**

* `m == matrix.length`
* `n == matrix[i].length`
* `1 <= m, n <= 100`
* `-100 <= matrix[i][j] <= 100`
* `-10^5 <= k <= 10^5`

**Follow up:** What if the number of rows is much larger than the number of columns?

## Solution

### Kadane's Algorithm by converting 2D array to 1D

```cpp
class Solution {
public:
    int result = INT_MIN;
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        if (cols > rows) {
            // Stores the 1D representation of the matrix row wise.
            vector<int> rowSum(cols);
            for (int i = 0; i < rows; i++) {
                // Initialize the 1D representation with 0s.
                fill(rowSum.begin(), rowSum.end(), 0);

                // We convert the matrix between rows i..row inclusive to 1D array
                for (int row = i; row < rows; row++) {
                    // Add the current row to the previous row.
                    // This converts the matrix between i..j to 1D array
                    for (int col = 0; col < cols; col++)
                        rowSum[col] += matrix[row][col];

                    // Run the 1D algorithm for `rowSum`
                    updateResult(rowSum, k);

                    // If result is k, this is the best possible answer, so return.
                    if (result == k)
                        return result;
                }
            }
        } else {
            // Stores the 1D representation of the matrix column wise.
            vector<int> colSum(rows);
            for (int i = 0; i < cols; i++) {
                // Initialize the 1D representation with 0s.
                fill(colSum.begin(), colSum.end(), 0);

                // We convert the matrix between columns i..col inclusive to 1D array
                for (int col = i; col < cols; col++) {
                    // Add the current column to the previous column.
                    for (int row = 0; row < rows; row++)
                        colSum[row] += matrix[row][col];

                    // Run the 1D algorithm for `colSum`
                    updateResult(colSum, k);
                    
                    // If Max is k, this is the best possible answer, so return.
                    if (result == k)
                        return result;
                }
            }
        }
        return result;
    }
    
    // Standard Kadane's algorithm.
    int getMaxKadane(vector<int>& nums) {
        int maxKadane = INT_MIN, currentMaxSum = 0;
        for (int& num : nums) {
            currentMaxSum = max(currentMaxSum + num, num);
            maxKadane = max(maxKadane, currentMaxSum);
        }
        return maxKadane;
    }
    void updateResult(vector<int>& nums, int k) {
        int kadaneSum = getMaxKadane(nums);

        // If max possible sum of any subarray of nums is <=k
        // use that result to compare with global maximum result and return
        if (kadaneSum <= k) {
            result = max(result, kadaneSum);
            return;
        }
        int sum = 0;

        // Container to store sorted prefix sums.
        set<int> sortedSum;
        set<int>::iterator it;

        // Add 0 as the prefix sum for an empty sub-array.
        sortedSum.insert(0);
        for (int& num : nums) {
            // Running Sum.
            sum += num;

            // Get X where Running sum - X <= k such that sum - X is closest to k.
            it = sortedSum.lower_bound(sum - k);

            // If such X is found in the prefix sums.
            // Get the sum of that sub array and update the global maximum result.
            if (it != sortedSum.end())
                result = max(result, sum - *it);

            // Insert the current running sum to the prefix sums container.
            sortedSum.insert(sum);
        }
    }
};
```

