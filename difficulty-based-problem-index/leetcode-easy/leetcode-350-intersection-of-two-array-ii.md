# Leetcode 350 Intersection of Two Array II

## Problem Statement

[https://leetcode.com/problems/intersection-of-two-arrays-ii/](https://leetcode.com/problems/intersection-of-two-arrays-ii/)

Given two integer arrays `nums1` and `nums2`, return _an array of their intersection_. Each element in the result must appear as many times as it shows in both arrays and you may return the result in **any order**.

**Example 1:**

```text
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
```

**Example 2:**

```text
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: 
[9,4] is also accepted.
```

**Constraints:**

* `1 <= nums1.length, nums2.length <= 1000`
* `0 <= nums1[i], nums2[i] <= 1000`

## Solution

```cpp
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        map<int,int> num_map;
        for(int i : nums1)
            num_map[i]++;
        for(int i : nums2)
        {
            if(num_map[i] != 0)
            {
                result.push_back(i);
                num_map[i]--;
            }
        }
        return result;
    }
};
```

