# Leetcode 28 Implement strStr\(\)

## Problem Statement

[https://leetcode.com/problems/implement-strstr/](https://leetcode.com/problems/implement-strstr/)

Implement [strStr\(\)](http://www.cplusplus.com/reference/cstring/strstr/).

Return the index of the first occurrence of needle in haystack, or `-1` if `needle` is not part of `haystack`.

**Clarification:**

What should we return when `needle` is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when `needle` is an empty string. This is consistent to C's [strstr\(\)](http://www.cplusplus.com/reference/cstring/strstr/) and Java's [indexOf\(\)](https://docs.oracle.com/javase/7/docs/api/java/lang/String.html#indexOf%28java.lang.String%29).

**Example 1:**

```text
Input: haystack = "hello", needle = "ll"
Output: 2
```

**Example 2:**

```text
Input: haystack = "aaaaa", needle = "bba"
Output: -1
```

**Example 3:**

```text
Input: haystack = "", needle = ""
Output: 0
```

**Constraints:**

* `0 <= haystack.length, needle.length <= 5 * 10^4`
* `haystack` and `needle` consist of only lower-case English characters.

## Solution

100% Faster and 99.2% memory Efficient

```cpp
class Solution {
public:
    int strStr(string haystack, string needle) {
        for(int i = 0; i + needle.size() - 1 < haystack.size(); i++)
        {
            bool match = true;
            for(int j = 0; j < needle.size(); j++)
                if(haystack[i+j] != needle[j]){
                    match = false;
                    break;
                }
            if(match) 
                return i;
        }
        return (needle.size()) ? -1 : 0;
    }
};
```

