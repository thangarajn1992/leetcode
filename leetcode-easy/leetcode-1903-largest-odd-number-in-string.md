# Leetcode 1903 Largest Odd Number in String

## Problem Statement

[https://leetcode.com/problems/largest-odd-number-in-string/](https://leetcode.com/problems/largest-odd-number-in-string/)

You are given a string `num`, representing a large integer. Return _the **largest-valued odd** integer \(as a string\) that is a **non-empty substring** of_ `num`_, or an empty string_ `""` _if no odd integer exists_.

A **substring** is a contiguous sequence of characters within a string.

**Example 1:**

```text
Input: num = "52"
Output: "5"
Explanation: 
The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
```

**Example 2:**

```text
Input: num = "4206"
Output: ""
Explanation: 
There are no odd numbers in "4206".
```

**Example 3:**

```text
Input: num = "35427"
Output: "35427"
Explanation: 
"35427" is already an odd number.
```

**Constraints:**

* `1 <= num.length <= 10^5`
* `num` only consists of digits and does not contain any leading zeros.

## Solution

```cpp
class Solution {
public:
    string largestOddNumber(string num) {
        int i = 0;
        for(i = num.size()-1; i >= 0; i--)
            if((num[i] - '0') % 2 == 1)
                break;
        return num.substr(0,i+1);
    }
};
```

