# Leetcode 300 Longest Increasing Subsequence

## Problem Statement

[https://leetcode.com/problems/longest-increasing-subsequence/](https://leetcode.com/problems/longest-increasing-subsequence/)

Given an integer array `nums`, return the length of the longest strictly increasing subsequence.

A **subsequence** is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, `[3,6,2,7]` is a subsequence of the array `[0,3,1,6,2,2,7]`.

**Example 1:**

```text
Input: nums = [10,9,2,5,3,7,101,18]
Output: 4
Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
```

**Example 2:**

```text
Input: nums = [0,1,0,3,2,3]
Output: 4
```

**Example 3:**

```text
Input: nums = [7,7,7,7,7,7,7]
Output: 1
```

**Constraints:**

* `1 <= nums.length <= 2500`
* `-10^4 <= nums[i] <= 10^4`

**Follow up:** Can you come up with an algorithm that runs in `O(n log(n))` time complexity?

## Solution

### Binary Search Approach

```cpp
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        for(int num = 0; num < nums.size(); num++)
        {
            if(num == 0 || nums[num] > sub.back())
                sub.push_back(nums[num]);
            else
            {
                int left = 0,  right = sub.size() - 1;
                int ind = -1;
                while(left <= right)
                {
                    int mid = left + (right- left)/2;
                    if(sub[mid] >= nums[num])
                    {
                        ind = mid;
                        right = mid - 1;
                    }
                    else
                    {
                        left = mid + 1;
                    }     
                }
                if(ind != -1) sub[ind] = nums[num];
            }
        }
        return sub.size();
    }
};
```

