# Leetcode 66 Plus One

## Problem Statement

[https://leetcode.com/problems/plus-one/](https://leetcode.com/problems/plus-one/)

Given a **non-empty** array of decimal digits representing a non-negative integer, increment one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contains a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

**Example 1:**

```text
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: 
The array represents the integer 123.
```

**Example 2:**

```text
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: 
The array represents the integer 4321.
```

**Example 3:**

```text
Input: digits = [0]
Output: [1]
```

**Constraints:**

* `1 <= digits.length <= 100`
* `0 <= digits[i] <= 9`

## Solution

```cpp
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int to_add = 1;
        for(int i = digits.size() - 1; to_add && i >= 0 ; i--)
        {
            digits[i] += to_add;
            to_add = digits[i] / 10;
            digits[i] %= 10;
        }
        if(to_add)
            digits.insert(digits.begin(), to_add);
        return digits;
    }
};
```

