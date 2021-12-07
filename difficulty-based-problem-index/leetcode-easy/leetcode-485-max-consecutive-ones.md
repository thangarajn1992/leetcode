# Leetcode 485 Max Consecutive Ones

## Problem Statement

[https://leetcode.com/problems/max-consecutive-ones/](https://leetcode.com/problems/max-consecutive-ones/)

Given a binary array `nums`, return _the maximum number of consecutive_ `1`_'s in the array_.

**Example 1:**

```
Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: 
The first two digits or the last three digits are consecutive 1s. 
The maximum number of consecutive 1s is 3.
```

**Example 2:**

```
Input: nums = [1,0,1,1,0,1]
Output: 2
```

**Constraints:**

* `1 <= nums.length <= 10^5`
* `nums[i]` is either `0` or `1`.

## Solution

### Sliding window of varying length

```cpp
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int currConsecutive = 0;
        int maxConsecutive = 0;
        
        for(int num : nums)
        {
            if(num == 0) // window ends
            {
                maxConsecutive = max(maxConsecutive, currConsecutive);
                currConsecutive = 0;
            }
            else
                currConsecutive++;
        }
        maxConsecutive = max(maxConsecutive, currConsecutive);
        return maxConsecutive;
    }
};
```
