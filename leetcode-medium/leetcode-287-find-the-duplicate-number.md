# Leetcode 287 Find the Duplicate Number

## Problem Statement

[https://leetcode.com/problems/find-the-duplicate-number/](https://leetcode.com/problems/find-the-duplicate-number/)

Given an array of integers `nums` containing `n + 1` integers where each integer is in the range `[1, n]` inclusive.

There is only **one repeated number** in `nums`, return _this repeated number_.

You must solve the problem **without** modifying the array `nums` and uses only constant extra space.

**Example 1:**

```text
Input: nums = [1,3,4,2,2]
Output: 2
```

**Example 2:**

```text
Input: nums = [3,1,3,4,2]
Output: 3
```

**Example 3:**

```text
Input: nums = [1,1]
Output: 1
```

**Example 4:**

```text
Input: nums = [1,1,2]
Output: 1
```

**Constraints:**

* `2 <= n <= 105`
* `nums.length == n + 1`
* `1 <= nums[i] <= n`
* All the integers in `nums` appear only **once** except for **precisely one integer** which appears **two or more** times.

**Follow up:**

* How can we prove that at least one duplicate number must exist in `nums`?
* Can you solve the problem in linear runtime complexity?

## Solution

### Floyd's Algorithm 0\(1\) space

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[0];
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);
        
        slow = nums[0];
        while(slow != fast)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
```

### Using set/bitmap/vector 0\(n\) space

```cpp
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> v(nums.size()+1,0);
        for(int e : nums)
        {
            v[e]++;
            if(v[e] > 1)
                return e;
        }
        return -1;
    }
};
```

