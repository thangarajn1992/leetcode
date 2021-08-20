# Leetcode 5 Longest Palindromic Substring

## Problem Statement

[https://leetcode.com/problems/longest-palindromic-substring/](https://leetcode.com/problems/longest-palindromic-substring/)

Given a string `s`, return _the longest palindromic substring_ in `s`.

**Example 1:**

```text
Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
```

**Example 2:**

```text
Input: s = "cbbd"
Output: "bb"
```

**Example 3:**

```text
Input: s = "a"
Output: "a"
```

**Example 4:**

```text
Input: s = "ac"
Output: "a"
```

**Constraints:**

* `1 <= s.length <= 1000`
* `s` consist of only digits and English letters \(lower-case and/or upper-case\),

## Solution

```cpp
class Solution {
public:

    string longestPalindrome(string s) {
        if(s.size() <= 1)
            return s;
        int start = 0, end = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int len = (s[i] == s[i+1]) ? 
                       max(expandAroundCenter(s, i, i), expandAroundCenter(s, i, i+1)):
                       expandAroundCenter(s, i, i);
            if(len > end - start)
            {
                start = i - (len - 1)/2;
                end = i + len/2;
            }
        }
        return s.substr(start, end - start + 1);
    }
    
    int expandAroundCenter(const string &s, int left, int right) const
    {
        while(left >= 0 && right < s.size() && s[left] == s[right])
            left--, right++;
        return right - left - 1;
    }
};
```

