# Leetcode 1930 Unique Length-3 Palindromic Subsequences

## Problem Statement

[https://leetcode.com/problems/unique-length-3-palindromic-subsequences/](https://leetcode.com/problems/unique-length-3-palindromic-subsequences/)

Given a string `s`, return _the number of **unique palindromes of length three** that are a **subsequence** of_ `s`.

Note that even if there are multiple ways to obtain the same subsequence, it is still only counted **once**.

A **palindrome** is a string that reads the same forwards and backwards.

A **subsequence** of a string is a new string generated from the original string with some characters \(can be none\) deleted without changing the relative order of the remaining characters.

* For example, `"ace"` is a subsequence of `"abcde"`.

**Example 1:**

```text
Input: s = "aabca"
Output: 3
Explanation: The 3 palindromic subsequences of length 3 are:
- "aba" (subsequence of "aabca")
- "aaa" (subsequence of "aabca")
- "aca" (subsequence of "aabca")
```

**Example 2:**

```text
Input: s = "adc"
Output: 0
Explanation: There are no palindromic subsequences of length 3 in "adc".
```

**Example 3:**

```text
Input: s = "bbcbaba"
Output: 4
Explanation: The 4 palindromic subsequences of length 3 are:
- "bbb" (subsequence of "bbcbaba")
- "bcb" (subsequence of "bbcbaba")
- "bab" (subsequence of "bbcbaba")
- "aba" (subsequence of "bbcbaba")
```

**Constraints:**

* `3 <= s.length <= 10^5`
* `s` consists of only lowercase English letters.

## Solution

```cpp
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26, INT_MAX); 
        vector<int> last(26,0);
        int res = 0;
        
        // store first and last occurance of each character
        for (int i = 0; i < s.size(); ++i) {
            if(first[s[i] - 'a'] > i)
                first[s[i] - 'a'] = i;
            last[s[i] - 'a'] = i;
        }
        
        // Find unique characters in between first and last occurance of character
        for (int i = 0; i < 26; ++i)
            if (first[i] < last[i])
                res += unordered_set<char>(s.begin() + first[i] + 1, s.begin() + last[i]).size();
        return res;
    }
};
```

