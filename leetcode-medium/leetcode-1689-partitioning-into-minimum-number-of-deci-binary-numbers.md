# Leetcode 1689 Partitioning Into Minimum Number Of Deci-Binary Numbers

## Problem Statement

A decimal number is called **deci-binary** if each of its digits is either `0` or `1` without any leading zeros. For example, `101` and `1100` are **deci-binary**, while `112` and `3001` are not.

Given a string `n` that represents a positive decimal integer, return _the **minimum** number of positive **deci-binary** numbers needed so that they sum up to_ `n`_._

**Example 1:**

```text
Input: n = "32"
Output: 3
Explanation: 10 + 11 + 11 = 32
```

**Example 2:**

```text
Input: n = "82734"
Output: 8
```

**Example 3:**

```text
Input: n = "27346209830709182346"
Output: 9
```

**Constraints:**

* `1 <= n.length <= 10^5`
* `n` consists of only digits.
* `n` does not contain any leading zeros and represents a positive integer.

## Solution

```cpp
class Solution {
public:
    int minPartitions(string n) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        int result = 0;
        for(char e : n)
        {
            result = max(result, e - '0');
            if(result == 9)
                break;
        }
        return result;
    }
};
```

