# Leetcode 349 Intersection of Two Arrays

## Problem Statement

[https://leetcode.com/problems/intersection-of-two-arrays/](https://leetcode.com/problems/intersection-of-two-arrays/)

Given two integer arrays `nums1` and `nums2`, return _an array of their intersection_. Each element in the result must be **unique** and you may return the result in **any order**.

**Example 1:**

```text
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
```

**Example 2:**

```text
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation:
[4,9] is also accepted.
```

**Constraints:**

* `1 <= nums1.length, nums2.length <= 1000`
* `0 <= nums1[i], nums2[i] <= 1000`

## Solution

```cpp
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        map<int,int> mp;
        for(int i : nums1)
            mp[i] = 1;
        for(int i : nums2)
            if(mp[i])
            {
                mp[i] = 0;
                result.push_back(i);
            }
        return result;
    }
};
```

