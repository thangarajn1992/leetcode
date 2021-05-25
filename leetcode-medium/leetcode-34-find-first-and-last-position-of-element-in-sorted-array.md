# Leetcode 34 Find First and Last Position of Element in Sorted Array

## Problem Statement

[https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/)

Given an array of integers `nums` sorted in ascending order, find the starting and ending position of a given `target` value.

If `target` is not found in the array, return `[-1, -1]`.

**Follow up:** Could you write an algorithm with `O(log n)` runtime complexity?

**Example 1:**

```text
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
```

**Example 2:**

```text
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
```

**Example 3:**

```text
Input: nums = [], target = 0
Output: [-1,-1]
```

**Constraints:**

* `0 <= nums.length <= 10^5`
* `-10^9 <= nums[i] <= 10^9`
* `nums` is a non-decreasing array.
* `-10^9 <= target <= 10^9`

## Solution

```cpp
vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res(2,-1);
    int start = 0;
    int end = nums.size() - 1;
    if(nums.size())
    {
        while(start <= end){
            int mid = (start + end) / 2;
            if(nums[mid] == target)
            {
                res[0] = mid;
                res[1] = mid;
                for(int i = 0; mid - i >= 0 || mid + i < nums.size(); i++)
                {
                    if(mid-i >= 0 && nums[mid-i] == target)
                        res[0] = mid-i;
                    if(mid + i < nums.size() && nums[mid+i] == target)
                        res[1] = mid+i;
                }
                break;
            }
            else if(nums[mid] > target)
            {
                end = mid - 1;
                continue;
            }
            else
            {
                start = mid + 1;
                continue;
            }
        }
    }
    return res;
}
```

