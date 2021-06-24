# Leetcode 171 Excel Sheet Column Number

## Problem Statement

[https://leetcode.com/problems/excel-sheet-column-number/](https://leetcode.com/problems/excel-sheet-column-number/)

Given a string `columnTitle` that represents the column title as appear in an Excel sheet, return _its corresponding column number_.

For example:

```text
A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
...
```

**Example 1:**

```text
Input: columnTitle = "A"
Output: 1
```

**Example 2:**

```text
Input: columnTitle = "AB"
Output: 28
```

**Example 3:**

```text
Input: columnTitle = "ZY"
Output: 701
```

**Example 4:**

```text
Input: columnTitle = "FXSHRXW"
Output: 2147483647
```

**Constraints:**

* `1 <= columnTitle.length <= 7`
* `columnTitle` consists only of uppercase English letters.
* `columnTitle` is in the range `["A", "FXSHRXW"]`.

## Solution

```cpp
class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0, n = columnTitle.size();
        for(int i = 0; i < n; i++)
            result += (columnTitle[i] - 'A' + 1) * pow(26, n-1-i);
        return result;
    }
};
```

