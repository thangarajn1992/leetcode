# Leetcode 583 Delete Operation for Two Strings

[Explanation](leetcode-583-delete-operation-for-two-strings.md#explanation)           [Solution](leetcode-583-delete-operation-for-two-strings.md#solution)

## Problem Statement

[https://leetcode.com/problems/delete-operation-for-two-strings/](https://leetcode.com/problems/delete-operation-for-two-strings/)

Given two strings `word1` and `word2`, return _the minimum number of **steps** required to make_ `word1` _and_ `word2` _the same_.

In one **step**, you can delete exactly one character in either string.

**Example 1:**

```
Input: word1 = "sea", word2 = "eat"
Output: 2
Explanation: 
You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
```

**Example 2:**

```
Input: word1 = "leetcode", word2 = "etco"
Output: 4
```

**Constraints:**

* `1 <= word1.length, word2.length <= 500`
* `word1` and `word2` consist of only lowercase English letters.

## Explanation

We can make use of Dynamic Programming to directly determine the number of deletions required till the current indices of the strings.

In order to do so, we make use of a 2-D `dp` array. Now, `dp[i][j]` refers to the number of deletions required to equalize the two strings if we consider the strings' length upto (i−1)th index and (j−1)th index for `s1` and `s2` respectively. Again, we fill in the `dp` array in a row-by-row order. Now, in order to fill the entry for `dp[i][j]`, we need to consider two cases only:

1. The characters `s1[i−1] `and `s2[j−1]`  match each other. In this case, we need to replicate the entry corresponding to`dp[i−1][j−1]`itself. This is because the matched character doesn't need to be deleted from any of the strings.
2. The characters `s1[i−1]` and` s2[j−1]` don't match with each other. In this case, we need to delete either the current character of `s1` or `s2.` Thus, an increment of 1 needs to be done relative to the entries corresponding to the previous indices. The two options available at this moment are `dp[i−1][j]` and `dp[i][j−1]`. Since, we are keeping track of the minimum number of deletions required, we pick up the minimum out of these two values.

At the end,`dp[m][n]` gives the required minimum number of deletions. Here, `m` and `n` refer to the lengths of `s1` and `s2`

## Solution

### Dynamic Programming with 2D Array

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int size1 = word1.size();
        int size2 = word2.size();
        int dp[size1 + 1][size2 + 1];
        for(int i = 0; i <= size1; i++)
            for(int j = 0; j <= size2; j++)
            {
                if(i == 0 || j == 0)
                    dp[i][j] = i + j;
                else if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1  + min(dp[i][j-1], dp[i-1][j]);
            }
        return dp[size1][size2];
    }
};
```

### Dynamic Programming with 1D Array

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<int> dp(word2.length() + 1);
        for(int i = 0; i <= word1.length(); i++)
        {
            vector<int> temp(word2.length() + 1);
            for(int j = 0; j <= word2.length(); j++)
            {
                if(i == 0 || j == 0)
                    temp[j] = i+j;
                else if(word1[i-1] == word2[j-1])
                    temp[j] = dp[j-1];
                else
                    temp[j] = 1 + min(dp[j], temp[j-1]);
            }
            dp = temp;
        }
        return dp[word2.length()];
    }
};
```
