# Leetcode 53 Maximum Subarray

## Problem Statement

[https://leetcode.com/problems/maximum-subarray/](https://leetcode.com/problems/maximum-subarray/)

Given an integer array `nums`, find the contiguous subarray \(containing at least one number\) which has the largest sum and return _its sum_.

**Example 1:**

```text
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.
```

**Example 2:**

```text
Input: nums = [1]
Output: 1
```

**Example 3:**

```text
Input: nums = [5,4,-1,7,8]
Output: 23
```

**Constraints:**

* `1 <= nums.length <= 3 * 10^4`
* `-10^5 <= nums[i] <= 10^5`

##  Solution

### Kadane's Algorithm

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxEnd = 0, maxSoFar = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++){
            maxEnd += nums[i];
           
            if(maxSoFar < maxEnd)
                maxSoFar = maxEnd;
            
            if(maxEnd < 0)
                maxEnd = 0;
        }
        return maxSoFar;
    }
};
```

### Divide and Conquer

```cpp
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return maxSubArray(nums, 0, nums.size() - 1);
    }
private:
    int maxSubArray(vector<int>& nums, int left, int right) {
        if (left > right) {
            return INT_MIN;
        }
        int mid = left + (right - left) / 2;
        
        // Find max in left and right sub-array
        int lmax = maxSubArray(nums, left, mid - 1);
        int rmax = maxSubArray(nums, mid + 1, right);
        
        // Find max that combines both left & right sub-array
        int max_left = 0, max_right = 0;
        for (int i = mid - 1, sum = 0; i >= left; i--) {
            sum += nums[i];
            max_left = max(sum, max_left);
        }
        for (int i = mid + 1, sum = 0; i <= right; i++) {
            sum += nums[i];
            max_right = max(sum, max_right);
        }
        return max(max(lmax, rmax), max_left + max_right + nums[mid]);
    }
};
```

