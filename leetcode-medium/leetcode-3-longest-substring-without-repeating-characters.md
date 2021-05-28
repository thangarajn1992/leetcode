# Leetcode 3 Longest Substring Without Repeating Characters

## Problem Statement

[https://leetcode.com/problems/longest-substring-without-repeating-characters/](https://leetcode.com/problems/longest-substring-without-repeating-characters/)

Given a string `s`, find the length of the **longest substring** without repeating characters.

**Example 1:**

```text
Input: s = "abcabcbb"
Output: 3
Explanation: 
The answer is "abc", with the length of 3.
```

**Example 2:**

```text
Input: s = "bbbbb"
Output: 1
Explanation: 
The answer is "b", with the length of 1.
```

**Example 3:**

```text
Input: s = "pwwkew"
Output: 3
Explanation: 
The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
```

**Example 4:**

```text
Input: s = ""
Output: 0
```

**Constraints:**

* `0 <= s.length <= 5 * 10^4`
* `s` consists of English letters, digits, symbols and spaces.

## Solution

```cpp
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n < 2)
            return n;
        int max_length = 0, start_index = 0, i = 0;
        vector<int> m(256, -1);
        m[s[0]] = 0;
        for(i = 1; i < n; i++)
        {
            if(m[s[i]] != -1 && m[s[i]] >= start_index)
            {
                if(i - start_index > max_length)
                    max_length = i - start_index;
                start_index = m[s[i]] + 1;
            }
            m[s[i]] = i;
        }
        return max_length > i-start_index ? max_length: i-start_index;
    }
};
```

