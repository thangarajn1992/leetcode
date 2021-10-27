# Leetcode 414 Third Maximum Number

## Problem Statement

[https://leetcode.com/problems/third-maximum-number/](https://leetcode.com/problems/third-maximum-number/)

Given an integer array `nums`, return _the **third distinct maximum** number in this array. If the third maximum does not exist, return the **maximum** number_.

**Example 1:**

```
Input: nums = [3,2,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2.
The third distinct maximum is 1.
```

**Example 2:**

```
Input: nums = [1,2]
Output: 2
Explanation:
The first distinct maximum is 2.
The second distinct maximum is 1.
The third distinct maximum does not exist, so the maximum (2) is returned instead.
```

**Example 3:**

```
Input: nums = [2,2,3,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2 (both 2's are counted together since they have the same value).
The third distinct maximum is 1.
```

**Constraints:**

* `1 <= nums.length <= 10^4`
* `-2^31 <= nums[i] <= 2^31 - 1`

&#x20; **Follow up:** Can you find an `O(n)` solution?

## Solution

### My Initial Solution : O(N) time and O(1) Space complexity

```cpp
class Solution {
public:
/* O(N) and O(1) Time Complexity: My Initial Solution */
    int thirdMax(vector<int>& nums) {
        long firstMax = LONG_MIN, secondMax = LONG_MIN, thirdMax = LONG_MIN;
        for(int index = 0; index < nums.size(); index++)
        {
            if(nums[index] > firstMax)
            {
                thirdMax = secondMax;
                secondMax = firstMax;
                firstMax = nums[index];   
            }
            else if(nums[index] < firstMax && nums[index] > secondMax)
            {
                thirdMax = secondMax;
                secondMax = nums[index];
            }
            else if(nums[index] < secondMax && nums[index] > thirdMax)
            {
                thirdMax = nums[index];
            }
        }
        if(thirdMax == LONG_MIN)
            return firstMax;
        else
            return thirdMax;
    }
};
```

### Using HashSet

```cpp
class Solution {
public:
    /* Using Set */
    int thirdMax(vector<int>& nums) {
        set<int> topThree;
        for(int num : nums)
        {
            topThree.insert(num);
            if(topThree.size() > 3)
                topThree.erase(topThree.begin());
        }
        if(topThree.size() == 3)
            return *topThree.begin();
        else
            return *topThree.rbegin();
    }
};
```
