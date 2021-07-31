# Leetcode 42 Trapping Rain Water

## Problem Statement

[https://leetcode.com/problems/trapping-rain-water/](https://leetcode.com/problems/trapping-rain-water/)

Given `n` non-negative integers representing an elevation map where the width of each bar is `1`, compute how much water it can trap after raining.

**Example 1:** ![](https://assets.leetcode.com/uploads/2018/10/22/rainwatertrap.png)

```text
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: 
The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
In this case, 6 units of rain water (blue section) are being trapped.
```

**Example 2:**

```text
Input: height = [4,2,0,3,2,5]
Output: 9
```

**Constraints:**

* `n == height.length`
* `0 <= n <= 3 * 10^4`
* `0 <= height[i] <= 10^5`

## Solution

### Two Pointer Approach

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        while (left < right) {
            if (height[left] < height[right]) 
            {
                height[left] >= left_max ? (left_max = height[left]) : 
                                            ans += (left_max - height[left]);
                ++left;
            }
            else 
            {
                height[right] >= right_max ? (right_max = height[right]) : 
                                             ans += (right_max - height[right]);
                --right;
            }
        }
        return ans;
    }
};
```

