# Leetcode 560 Subarray Sum Equals K

## Problem Statement

[https://leetcode.com/problems/subarray-sum-equals-k/](https://leetcode.com/problems/subarray-sum-equals-k/)

Given an array of integers `nums` and an integer `k`, return _the total number of continuous subarrays whose sum equals to `k`_.

**Example 1:**

```
Input: nums = [1,1,1], k = 2
Output: 2
```

**Example 2:**

```
Input: nums = [1,2,3], k = 3
Output: 2
```

**Constraints:**

* `1 <= nums.length <= 2 * 10^4`
* `-1000 <= nums[i] <= 1000`
* `-10^7 <= k <= 10^7`

## Solution

### Hash-Map Approach

The HashMap will store with the key being any particular sum, and the value being the number of times it has happened till the current iteration of the loop as we traverse the array from left to right.

&#x20;For example: k = 26. If a sub-array sums up to k, then the sum at the end of this sub-array will be sumEnd = sumStart + k. That implies: sumStart = sumEnd - k.&#x20;

Suppose, at index 10, sum = 50, and the next 6 numbers are 8,-5,-3,10,15,1.&#x20;

At index 13, sum will be 50 again (the numbers from indexes 11 to 13 add up to 0).&#x20;

Then at index 16, sum = 76. Now, when we reach index 16, sum - k = 76 - 26 = 50.&#x20;

So, if this is the end index of a sub-array(s) which sums up to k, then before this, just before the start of the sub-array, the sum should be 50.&#x20;

As we found sum = 50 at two places before reaching index 16, we indeed have two sub-arrays which sum up to k (26): from indexes 14 to 16 and from indexes 11 to 16.

```cpp
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, sum = 0;
        map<int,int> sumOccurences;
        sumOccurences[0] = 1;
        
        for(int &num : nums)
        {
            sum += num;
            if(sumOccurences[sum - k] > 0)
            {
                count += sumOccurences[sum - k];
            }
            sumOccurences[sum] += 1;
        }
        return count;
    }
};
```
