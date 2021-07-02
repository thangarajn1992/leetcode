# Leetcode 88 Merge Sorted Array

## Problem Statement

[https://leetcode.com/problems/merge-sorted-array/](https://leetcode.com/problems/merge-sorted-array/)

Given two sorted integer arrays `nums1` and `nums2`, merge `nums2` into `nums1` as one sorted array.

The number of elements initialized in `nums1` and `nums2` are `m` and `n` respectively. You may assume that `nums1` has a size equal to `m + n` such that it has enough space to hold additional elements from `nums2`.

**Example 1:**

```text
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]
```

**Example 2:**

```text
Input: nums1 = [1], m = 1, nums2 = [], n = 0
Output: [1]
```

**Constraints:**

* `nums1.length == m + n`
* `nums2.length == n`
* `0 <= m, n <= 200`
* `1 <= m + n <= 200`
* `-10^9 <= nums1[i], nums2[i] <= 10^9`

  **Follow up:** Can you come up with an algorithm that runs in `O(m + n)` time?

## Solution

```cpp
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int n1 = m - 1;
        int n2 = n - 1;
        for(int i = m+n-1; i >= 0; i--)
        {
            if(n2 < 0) return;
            if(n1 >= 0 && nums1[n1] > nums2[n2])
                nums1[i] = nums1[n1--];
            else
                nums1[i] = nums2[n2--];
        }
    }
};
```

