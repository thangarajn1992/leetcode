# Leetcode 55 Jump Game

## Problem Statement

Given an array of non-negative integers `nums`, you are initially positioned at the **first index** of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

**Example 1:**

```
Input: nums = [2,3,1,1,4]
Output: true
Explanation: 
Jump 1 step from index 0 to 1, then 3 steps to the last index.
```

**Example 2:**

```
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
        int reachableIndex = 0, len = nums.size();
        for(int index = 0; index < len ; index++){
            if(reachableIndex < index) 
                return 0;
            reachableIndex = max(reachableIndex, index+nums[index]) ;
        }
        return reachableIndex >= len-1 ;
    }
};
```
