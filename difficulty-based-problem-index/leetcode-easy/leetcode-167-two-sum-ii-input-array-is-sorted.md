# Leetcode 167 Two Sum II - Input array is sorted

## Problem Statement

[https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)

Given an array of integers `numbers` that is already _**sorted in non-decreasing order**_, find two numbers such that they add up to a specific `target` number.

Return _the indices of the two numbers \(**1-indexed**\) as an integer array_ `answer` _of size_ `2`_, where_ `1 <= answer[0] < answer[1] <= numbers.length`.

The tests are generated such that there is **exactly one solution**. You **may not** use the same element twice.

**Example 1:**

```text
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.
```

**Example 2:**

```text
Input: numbers = [2,3,4], target = 6
Output: [1,3]
```

**Example 3:**

```text
Input: numbers = [-1,0], target = -1
Output: [1,2]
```

**Constraints:**

* `2 <= numbers.length <= 3 * 10^4`
* `-1000 <= numbers[i] <= 1000`
* `numbers` is sorted in **non-decreasing order**.
* `-1000 <= target <= 1000`
* The tests are generated such that there is **exactly one solution**.

## Solution

```cpp
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size()-1;
        while(left < right)
        {
            int sum = numbers[left] + numbers[right];
            if(sum == target)
                break;
            if(sum < target)
            {
                left++;
                while(left < right && numbers[left] == numbers[left-1])
                    left++;
            }
            else
            {
                right--;
                while(left < right && numbers[right] == numbers[right+1])
                    right--;
            }
        }
        return {left+1, right+1};
    }
};
```

