# Leetcode 242 Valid Anagram

## Problem Statement

[https://leetcode.com/problems/valid-anagram/](https://leetcode.com/problems/valid-anagram/)

Given two strings `s` and `t`, return `true` _if_ `t` _is an anagram of_ `s`_, and_ `false` _otherwise_.

**Example 1:**

```text
Input: s = "anagram", t = "nagaram"
Output: true
```

**Example 2:**

```text
Input: s = "rat", t = "car"
Output: false
```

**Constraints:**

* `1 <= s.length, t.length <= 5 * 10^4`
* `s` and `t` consist of lowercase English letters.

## Solution

```cpp
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        int count[26] = {0};
        for(char c : s)
            count[c - 'a']++;
        for(char c : t)
        {
            if(count[c - 'a'] == 0)
                return false;
            count[c - 'a']--;
        }
        return true;
    }
};
```

