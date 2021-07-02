# Leetcode 1876 Substrings of Size Three with Distinct Characters

## Problem Statement

[https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/](https://leetcode.com/problems/substrings-of-size-three-with-distinct-characters/)

A string is **good** if there are no repeated characters.

Given a string `s`​​​​​, return _the number of **good substrings** of length **three** in_ `s`​​​​​​.

Note that if there are multiple occurrences of the same substring, every occurrence should be counted.

A **substring** is a contiguous sequence of characters in a string.

**Example 1:**

```text
Input: s = "xyzzaz"
Output: 1
Explanation: 
There are 4 substrings of size 3: "xyz", "yzz", "zza", and "zaz". 
The only good substring of length 3 is "xyz".
```

**Example 2:**

```text
Input: s = "aababcabc"
Output: 4
Explanation: 
There are 7 substrings of size 3: "aab", "aba", "bab", "abc", "bca", "cab", and "abc".
The good substrings are "abc", "bca", "cab", and "abc".
```

**Constraints:**

* `1 <= s.length <= 100`
* `s`​​​​​​ consists of lowercase English letters.

## Solution

```cpp
class Solution {
public:
    int countGoodSubstrings(string s) {
        int count = 0;
        for(int i = 1; i < s.size() - 1; i++)
            if(s[i] != s[i-1] && s[i] != s[i+1] && s[i-1] != s[i+1])
                count++;
        return count;
    }
};
```

