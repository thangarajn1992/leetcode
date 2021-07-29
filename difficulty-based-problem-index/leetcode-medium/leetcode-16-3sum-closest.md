# Leetcode 16 3Sum Closest

## Problem Statement

[https://leetcode.com/problems/3sum-closest/](https://leetcode.com/problems/3sum-closest/)

Given an array `nums` of _n_ integers and an integer `target`, find three integers in `nums` such that the sum is closest to `target`. Return the sum of the three integers. You may assume that each input would have exactly one solution.

**Example 1:**

```text
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
```

**Constraints:**

* `3 <= nums.length <= 10^3`
* `-10^3 <= nums[i] <= 10^3`
* `-10^4 <= target <= 10^4`

## Solution

```cpp
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int diff = INT_MAX, size = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < size && diff != 0; i++) {
            int low = i + 1, high = size - 1;
            while (low < high) {
                int sum = nums[i] + nums[low] + nums[high];
                if (abs(target - sum) < abs(diff))
                    diff = target - sum;
                if (sum < target)
                    low++;
                else
                    high--;
            }
        }
        return target - diff;
    }      
};
```

