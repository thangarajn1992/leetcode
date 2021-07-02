# Leetcode 1695 Maximum Erasure Value

## Problem Statement

[https://leetcode.com/problems/maximum-erasure-value/](https://leetcode.com/problems/maximum-erasure-value/)

You are given an array of positive integers `nums` and want to erase a subarray containing **unique elements**. The **score** you get by erasing the subarray is equal to the **sum** of its elements.

Return _the **maximum score** you can get by erasing **exactly one** subarray._

An array `b` is called to be a subarray of `a` if it forms a contiguous subsequence of `a`, that is, if it is equal to `a[l],a[l+1],...,a[r]` for some `(l,r)`.

**Example 1:**

```text
Input: nums = [4,2,4,5,6]
Output: 17
Explanation: The optimal subarray here is [2,4,5,6].
```

**Example 2:**

```text
Input: nums = [5,2,1,2,5,2,1,2,5]
Output: 8
Explanation: The optimal subarray here is [5,2,1] or [1,2,5].
```

**Constraints:**

* `1 <= nums.length <= 10^5`
* `1 <= nums[i] <= 10^4`

## Solution

```cpp
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int result = 0, start_index = 0, curr_cnt = 0;
        map<int,int> m;
        vector<int> prefix_sum(nums.size()+1, 0);
        for(int i = 0; i < nums.size(); i++)
        {
            prefix_sum[i+1] = prefix_sum[i] + nums[i];
            if(m.find(nums[i]) != m.end() && m[nums[i]] >= start_index) 
            {
                result = max(result, curr_cnt);
                curr_cnt -= (prefix_sum[m[nums[i]] + 1] - prefix_sum[start_index]);
                start_index = m[nums[i]] + 1;   
            }
            m[nums[i]] = i;
            curr_cnt += nums[i];
        }
        result = max(result, curr_cnt);
        return result;
    }
};
```

