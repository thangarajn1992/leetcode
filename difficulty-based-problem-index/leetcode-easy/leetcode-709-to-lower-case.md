# Leetcode 709 To Lower Case

## Problem Statement

[https://leetcode.com/problems/to-lower-case/](https://leetcode.com/problems/to-lower-case/)

Given a string `s`, return _the string after replacing every uppercase letter with the same lowercase letter_.

**Example 1:**

```text
Input: s = "Hello"
Output: "hello"
```

**Example 2:**

```text
Input: s = "here"
Output: "here"
```

**Example 3:**

```text
Input: s = "LOVELY"
Output: "lovely"
```

**Constraints:**

* `1 <= s.length <= 100`
* `s` consists of printable ASCII characters.

## Solution

```cpp
class Solution {
public:
    string toLowerCase(string s) {
        // Cap A to Z ( 65 - 90) 
        // Lower A to Z ( 97 - 122)
        for(auto &c: s)
            if(c >= 65 && c <= 90)
                c += 32;
        return s;
    }
};
```

