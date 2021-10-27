# Leetcode 33 Search in Rotated Sorted Array

## Problem Statement

[https://leetcode.com/problems/search-in-rotated-sorted-array/](https://leetcode.com/problems/search-in-rotated-sorted-array/)

There is an integer array `nums` sorted in ascending order (with **distinct** values).

Prior to being passed to your function, `nums` is **rotated** at an unknown pivot index `k` (`0 <= k < nums.length`) such that the resulting array is `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]` (**0-indexed**). For example, `[0,1,2,4,5,6,7]` might be rotated at pivot index `3` and become `[4,5,6,7,0,1,2]`.

Given the array `nums` **after** the rotation and an integer `target`, return _the index of_ `target` _if it is in_ `nums`_, or_ `-1` _if it is not in_ `nums`.

You must write an algorithm with `O(log n)` runtime complexity.

**Example 1:**

```
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
```

**Example 2:**

```
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
```

**Example 3:**

```
Input: nums = [1], target = 0
Output: -1
```

**Constraints:**

* `1 <= nums.length <= 5000`
* `-10^4 <= nums[i] <= 10^4`
* All values of `nums` are **unique**.
* `nums` is guaranteed to be rotated at some pivot.
* `-10^4 <= target <= 10^4`

## Solution

```cpp
class Solution {
public:
    int search(vector<int>&A ,int target) {
        int n = A.size();
        int left = 0, right = n-1;
        // find the index of the smallest value using binary search.
        // Loop will terminate since mid < hi, and lo or hi will shrink by at least 1.
        // Proof by contradiction that mid < hi: if mid==hi, then lo==hi and loop would have been terminated.
        while(left < right){
            int mid = left + (right - left)/2;
            if(A[mid] > A[right]) 
                left = mid+1;
            else 
                right = mid;
        }
        // lo == hi is the index of the smallest value and also the number of places rotated.
        int rotatedBy = left;
        left = 0; right = n-1;
        // The usual binary search and accounting for rotation.
        while(left <= right){
            int mid = left + (right - left)/2;
            int realmid = (mid + rotatedBy) % n;
            if(A[realmid] == target)
                return realmid;
            if(A[realmid] < target)
                left = mid+1;
            else 
                right = mid-1;
        }
        return -1;
    }
};
```
