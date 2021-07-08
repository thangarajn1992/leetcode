# Leetcode 718 Maximum Length of Repeated Subarray

## Problem Statement

[https://leetcode.com/problems/maximum-length-of-repeated-subarray/](https://leetcode.com/problems/maximum-length-of-repeated-subarray/)

Given two integer arrays `nums1` and `nums2`, return _the maximum length of a subarray that appears in **both** arrays_.

**Example 1:**

```text
Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].
```

**Example 2:**

```text
Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
Output: 5
```

**Constraints:**

* `1 <= nums1.length, nums2.length <= 1000`
* `0 <= nums1[i], nums2[i] <= 100`

## Solution

### Dynamic Programming Approach

```cpp
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        vector<vector<int>> memo(nums1.size() + 1, vector<int>(nums2.size()+1, 0));
        for (int i = nums1.size() - 1; i >= 0; --i) {
            for (int j = nums2.size() - 1; j >= 0; --j) {
                if (nums1[i] == nums2[j]) {
                    memo[i][j] = memo[i+1][j+1] + 1;
                    if (ans < memo[i][j]) 
                        ans = memo[i][j];
                }
            }
        }
        return ans;       
    }
};
```

