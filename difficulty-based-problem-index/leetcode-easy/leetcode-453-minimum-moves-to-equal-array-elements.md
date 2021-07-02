# Leetcode 453 Minimum Moves to Equal Array Elements

## Problem Statement

[https://leetcode.com/problems/minimum-moves-to-equal-array-elements/](https://leetcode.com/problems/minimum-moves-to-equal-array-elements/)

Given an integer array `nums` of size `n`, return _the minimum number of moves required to make all array elements equal_.

In one move, you can increment `n - 1` elements of the array by `1`.

**Example 1:**

```text
Input: nums = [1,2,3]
Output: 3
Explanation: 
Only three moves are needed (remember each move increments two elements):
[1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
```

**Example 2:**

```text
Input: nums = [1,1,1]
Output: 0
```

**Constraints:**

* `n == nums.length`
* `1 <= nums.length <= 10^5`
* `-10^9 <= nums[i] <= 10^9`
* The answer is guaranteed to fit in a **32-bit** integer.

## Explanation

1. Get the minimum element of the array
2. Iterate over the elements of the array and keep counting the number of increment that is needed to make the min element to become the element in the array.
3. For eg: \[ 1, 5 \], min element is 1. and it takes 4 increments to make it equal to the other array element.

## Solution

```cpp
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int low = *min_element(nums.begin(), nums.end());
        int res = 0;
        for(int e : nums)
            res += e - low;
        return res;
    }
};
```

