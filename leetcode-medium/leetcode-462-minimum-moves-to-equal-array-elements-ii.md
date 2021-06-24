# Leetcode 462 Minimum Moves to Equal Array Elements II

## Problem Statement

Given an integer array `nums` of size `n`, return _the minimum number of moves required to make all array elements equal_.

In one move, you can increment or decrement an element of the array by `1`.

**Example 1:**

```text
Input: nums = [1,2,3]
Output: 2
Explanation:
Only two moves are needed (remember each move increments or decrements one element):
[1,2,3]  =>  [2,2,3]  =>  [2,2,2]
```

**Example 2:**

```text
Input: nums = [1,10,2,9]
Output: 16
```

**Constraints:**

* `n == nums.length`
* `1 <= nums.length <= 10^5`
* `-10^9 <= nums[i] <= 10^9`

## Solution

```cpp
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        ios::sync_with_stdio(false); cin.tie(nullptr);
        sort(nums.begin(), nums.end());
        int mid = nums.size()/2, res = 0;
        for(int i = 0; i < nums.size(); i++)
            res += abs(nums[i] - nums[mid]);
        return res;
    }
};
```

