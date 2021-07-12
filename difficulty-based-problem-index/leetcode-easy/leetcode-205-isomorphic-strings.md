# Leetcode 205 Isomorphic Strings

## Problem Statement

[https://leetcode.com/problems/isomorphic-strings/](https://leetcode.com/problems/isomorphic-strings/)

Given two strings `s` and `t`, _determine if they are isomorphic_.

Two strings `s` and `t` are isomorphic if the characters in `s` can be replaced to get `t`.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

**Example 1:**

```text
Input: s = "egg", t = "add"
Output: true
```

**Example 2:**

```text
Input: s = "foo", t = "bar"
Output: false
```

**Example 3:**

```text
Input: s = "paper", t = "title"
Output: true
```

**Constraints:**

* `1 <= s.length <= 5 * 10^4`
* `t.length == s.length`
* `s` and `t` consist of any valid ascii character.

## Solution

```cpp
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> s_to_t(128, -1); // Last index match
        vector<int> t_to_s(128, -1); // Last index match
        for(int i = 0; i < s.size(); i++)
        {
            if(s_to_t[s[i]] != t_to_s[t[i]])
                return false;
            
            s_to_t[s[i]] = i; // Storing the last common index.
            t_to_s[t[i]] = i;
        }
        return true;
    }
};
```

