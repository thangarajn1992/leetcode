# Leetcode 1909 Remove One Element to Make the Array Strictly Increasing

## Problem Statement

[https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/](https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/)

Given a **0-indexed** integer array `nums`, return `true` _if it can be made **strictly increasing** after removing **exactly one** element, or_ `false` _otherwise. If the array is already strictly increasing, return_ `true`.

The array `nums` is **strictly increasing** if `nums[i - 1] < nums[i]` for each index `(1 <= i < nums.length).`

**Example 1:**

```text
Input: nums = [1,2,10,5,7]
Output: true
Explanation: By removing 10 at index 2 from nums, it becomes [1,2,5,7].
[1,2,5,7] is strictly increasing, so return true.
```

**Example 2:**

```text
Input: nums = [2,3,1,2]
Output: false
Explanation:
[3,1,2] is the result of removing the element at index 0.
[2,1,2] is the result of removing the element at index 1.
[2,3,2] is the result of removing the element at index 2.
[2,3,1] is the result of removing the element at index 3.
No resulting array is strictly increasing, so return false.
```

**Example 3:**

```text
Input: nums = [1,1,1]
Output: false
Explanation: The result of removing any element is [1,1].
[1,1] is not strictly increasing, so return false.
```

**Example 4:**

```text
Input: nums = [1,2,3]
Output: true
Explanation: [1,2,3] is already strictly increasing, so return true.
```

**Constraints:**

* `2 <= nums.length <= 1000`
* `1 <= nums[i] <= 1000`

**Similar Problem** :

[Non-decreasing Array](../leetcode-medium/leetcode-665-non-decreasing-array.md)

## Solution

```cpp
class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int prev = nums[0];
        int allowance = 1;
        for(int index = 1; i < nums.size(); index++)
        {
            if(nums[index] > prev)
                prev = nums[index];
            else
            {
                if(allowance == 0)
                    return false;
                allowance--;
                if(index - 2 < 0 || nums[index] >= nums[index-2])
                    prev = nums[index];
            }
        }
        return true;
    }
};
```

