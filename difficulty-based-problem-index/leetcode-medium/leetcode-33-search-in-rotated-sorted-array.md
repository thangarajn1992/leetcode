# Leetcode 33 Search in Rotated Sorted Array

## Problem Statement

[https://leetcode.com/problems/search-in-rotated-sorted-array/](https://leetcode.com/problems/search-in-rotated-sorted-array/)

There is an integer array `nums` sorted in ascending order \(with **distinct** values\).

Prior to being passed to your function, `nums` is **rotated** at an unknown pivot index `k` \(`0 <= k < nums.length`\) such that the resulting array is `[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]]` \(**0-indexed**\). For example, `[0,1,2,4,5,6,7]` might be rotated at pivot index `3` and become `[4,5,6,7,0,1,2]`.

Given the array `nums` **after** the rotation and an integer `target`, return _the index of_ `target` _if it is in_ `nums`_, or_ `-1` _if it is not in_ `nums`.

You must write an algorithm with `O(log n)` runtime complexity.

**Example 1:**

```text
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4
```

**Example 2:**

```text
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
```

**Example 3:**

```text
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
    int bs(vector<int>& A, int low, int high, int x)
    {
        while(low <= high)
        {
            int mid = (low + high )/2 ;
            
            if(A[mid] == x)
                return mid;
           
            else if (A[mid] > x)
                    high = mid - 1;
            else 
                low = mid + 1;   
        } 
        return -1;
    }
    
    int pivot (vector<int> nums,int n)
    {
        int l = 0, r = nums.size()-1, mid = 0;
            
		// Modified binary search to find pivot (k)
        while(r > l){
            mid = l + (r-l)/2;
            
            if(nums[mid] > nums[r])
                l= mid+1;
            
            else
                r = mid;
        }
        return l-1;  
    }
    
    int search(vector<int>& nums, int target) {
       
        int n = nums.size();
        int p = pivot(nums,n);    
        if(nums[0] <= target && p >= 0)
            return bs(nums, 0, p, target);
        else
            return bs(nums, p+1, n-1, target);      
    }
};
```

