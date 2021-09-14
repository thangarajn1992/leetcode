# Leetcode 917 Reverse Only Letters

## Problem Statement

[https://leetcode.com/problems/reverse-only-letters/](https://leetcode.com/problems/reverse-only-letters/)

Given a string `s`, reverse the string according to the following rules:

* All the characters that are not English letters remain in the same position.
* All the English letters \(lowercase or uppercase\) should be reversed.

Return `s` _after reversing it_.

**Example 1:**

```text
Input: s = "ab-cd"
Output: "dc-ba"
```

**Example 2:**

```text
Input: s = "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"
```

**Example 3:**

```text
Input: s = "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"
```

**Constraints:**

* `1 <= s.length <= 100`
* `s` consists of characters with ASCII values in the range `[33, 122]`.
* `s` does not contain `'\"'` or `'\\'`.

## Solution

```cpp
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int start = 0, end = s.size()-1;
        while(start < end && isalpha(s[start]) == false)
            start++;
        while(end > start && isalpha(s[end]) == false)
            end--;        
        while(start < end)
        {
            //swap them
            char c = s[start];
            s[start] = s[end];
            s[end] = c;
            start++, end--;
            while(start < end && isalpha(s[start]) == false)
                start++;
            while(end > start && isalpha(s[end]) == false)
                end--;
        }
        return s;
    }
};
```

