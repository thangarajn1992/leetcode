# Leetcode 905 Sort Array By Parity

## Problem Statement

[https://leetcode.com/problems/sort-array-by-parity/](https://leetcode.com/problems/sort-array-by-parity/)

Given an integer array `nums`, move all the even integers at the beginning of the array followed by all the odd integers.

Return _**any array** that satisfies this condition_.

**Example 1:**

```text
Input: nums = [3,1,2,4]
Output: [2,4,3,1]
Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
```

**Example 2:**

```text
Input: nums = [0]
Output: [0]
```

**Constraints:**

* `1 <= nums.length <= 5000`
* `0 <= nums[i] <= 5000`

## Solution

### Two pointer approach

```cpp
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int size = nums.size();
        int left = 0, right = size-1; 
        while(left < right)
        {
            // if odd occurs before even number, swap them
            if(nums[left] % 2 > nums[right] % 2)
                swap(nums[left], nums[right]);
            
            // if even is already at right place, move to next index
            if(nums[left] % 2 == 0)
                left++;
            
            // if odd is already at right place, move to next index
            if(nums[right] % 2 == 1)
                right--;
        }
        return nums;
    }
};
```

