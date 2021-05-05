# Leetcode 55 Jump Game

## Problem Statement

Given an array of non-negative integers `nums`, you are initially positioned at the **first index** of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

**Example 1:**

```text
Input: nums = [2,3,1,1,4]
Output: true
Explanation: 
Jump 1 step from index 0 to 1, then 3 steps to the last index.
```

**Example 2:**

```text
Input: nums = [3,2,1,0,4]
Output: false
Explanation: 
You will always arrive at index 3 no matter what. 
Its maximum jump length is 0, which makes it impossible to reach the last index.
```

**Constraints:**

* `1 <= nums.length <= 3 * 10^4`
* `0 <= nums[i] <= 10^5`

## Solution

```cpp
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_so_far = 0, len = nums.size();
        for(int i = 0; i < len ; i++){
            if(max_so_far < i) return 0;
            max_so_far = max(max_so_far, i+nums[i]) ;
        }
        return max_so_far >= len-1 ;
    }
};
```

