# Leetcode 915 Partition Array into Disjoint Intervals

## Problem Statement

[https://leetcode.com/problems/partition-array-into-disjoint-intervals/](https://leetcode.com/problems/partition-array-into-disjoint-intervals/)

Given an array `nums`, partition it into two \(contiguous\) subarrays `left` and `right` so that:

* Every element in `left` is less than or equal to every element in `right`.
* `left` and `right` are non-empty.
* `left` has the smallest possible size.

Return the **length** of `left` after such a partitioning.  It is guaranteed that such a partitioning exists.

**Example 1:**

```text
Input: nums = [5,0,3,8,6]
Output: 3
Explanation: left = [5,0,3], right = [8,6]
```

**Example 2:**

```text
Input: nums = [1,1,1,0,6,12]
Output: 4
Explanation: left = [1,1,1,0], right = [6,12]
```

**Note:**

1. `2 <= nums.length <= 30000`
2. `0 <= nums[i] <= 10^6`
3. It is guaranteed there is at least one way to partition `nums` as described.

## Solution

### My Approach

The main idea is to figure out the lowest point after which the elements are always in ascending order.

1. Start with first element of the array as left partition. Mark that as left-max and right-max.
2. Start processing elements of right partition
   1. When we see an element lesser than left-max, then we need that element to be in left partition. Update left-max  = right-max \( max element seen so far \)and left-partition size accordingly.
3. Keep repeating this process until we process all the elements.
4. Last updated left-partition size is the minimum left partition size possible.

```cpp
class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        int right_max = nums[0];
        int left_max = nums[0];

        int left_size = 1;
        for(int i = 1; i < nums.size() ; i++)
        {
            if(nums[i] < left_max)
            {
                left_size = i+1;
                left_max = right_max;
            }
            
            if(right_max < nums[i])
                right_max = nums[i];
        }
        return left_size;
    }
};
```

