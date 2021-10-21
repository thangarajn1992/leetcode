# Leetcode 516 Longest Palindromic Subsequence

## Problem Statement

[https://leetcode.com/problems/longest-palindromic-subsequence/](https://leetcode.com/problems/longest-palindromic-subsequence/)

Given a string `s`, find _the longest palindromic **subsequence**'s length in_ `s`.

A **subsequence** is a sequence that can be derived from another sequence by deleting some or no elements without changing the order of the remaining elements.

**Example 1:**

```
Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".
```

**Example 2:**

```
Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".
```

**Constraints:**

* `1 <= s.length <= 1000`
* `s` consists only of lowercase English letters.

## Solution

### Dynamic Programming + Memoization

Let dp(l, r) denote the length of the longest palindromic subsequence of s\[l...r].

There are 2 options:

1. If `s[l] == s[r]`, then `dp[l][r] = dp[l+1][r-1] + 2`
2. else if `s[l] != s[r]` then `dp[l][r] = max(dp[l+1][r], dp[l][r-1])`
3. Store the calculated value to avoid duplicate calculation.

```cpp
class Solution {
public:
    int preCalculated[1000][1000] = {};
    int longestPalindromeSubseq(const string& s) {
        return dp(s, 0, s.size() - 1);
    }
    int dp(const string& s, int l, int r) {
        if (l > r) // Return 0 since it's empty string
            return 0; 
        if (l == r) // Return 1 since it has 1 character
            return 1; 
        if (preCalculated[l][r] != 0) 
            return preCalculated[l][r];
        if (s[l] == s[r])
            return preCalculated[l][r] = dp(s, l+1, r-1) + 2;
        return preCalculated[l][r] = max(dp(s, l+1, r), dp(s, l, r-1));
    }
};
```
