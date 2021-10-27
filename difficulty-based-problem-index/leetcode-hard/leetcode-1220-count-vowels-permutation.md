# Leetcode 1220 Count Vowels Permutation

## Problem Statement

[https://leetcode.com/problems/count-vowels-permutation/](https://leetcode.com/problems/count-vowels-permutation/)

Given an integer `n`, your task is to count how many strings of length `n` can be formed under the following rules:

* Each character is a lower case vowel (`'a'`, `'e'`, `'i'`, `'o'`, `'u'`)
* Each vowel `'a'` may only be followed by an `'e'`.
* Each vowel `'e'` may only be followed by an `'a'` or an `'i'`.
* Each vowel `'i'` **may not** be followed by another `'i'`.
* Each vowel `'o'` may only be followed by an `'i'` or a `'u'`.
* Each vowel `'u'` may only be followed by an `'a'.`

Since the answer may be too large, return it modulo `10^9 + 7.`

**Example 1:**

```
Input: n = 1
Output: 5
Explanation: All possible strings are: "a", "e", "i" , "o" and "u".
```

**Example 2:**

```
Input: n = 2
Output: 10
Explanation: 
All possible strings are: "ae", "ea", "ei", "ia", "ie", "io", "iu", "oi", "ou" and "ua".
```

**Example 3: **

```
Input: n = 5
Output: 68
```

**Constraints:**

* `1 <= n <= 2 * 10^4`

## Solution

### My DP Based approach

```cpp
class Solution {
public:
    int mod = pow(10,9) + 7;
    int countVowelPermutation(int n) {
        int result = 0;
        
        // Combo denotes "Char" can come after which characters
        vector<vector<int>> combo = {{1,2,4}, {0,2}, {1,3}, {2}, {2,3}};
        
        // dp[i][j] denotes no. of combo that ends with char 'j' and of length 'i'
        vector<vector<long long int>> dp(n+1,vector<long long int>(5,0));
        
        // For length 1, all count is 1.
        for(int i = 0 ; i < 5; i++)
            dp[1][i] = 1;
        
        for(int i = 2; i <= n; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                for(int k = 0; k < combo[j].size(); k++)
                    dp[i][j] += dp[i-1][combo[j][k]];
                dp[i][j] %= mod;
            }
        }
        
        for(int i = 0; i < 5; i++)
            result = (result + dp[n][i] ) % mod;
        return result;
    }
};
```

### Another Better Approach

```cpp
class Solution {
public:
    int countVowelPermutation(int n) {
        
        long aCount = 1, eCount = 1, iCount = 1, oCount = 1, uCount = 1;
        long aCountNew, eCountNew, iCountNew, oCountNew, uCountNew;
        int MOD = 1000000007;
        for(int i = 1 ; i < n; i++){
            aCountNew = (eCount + iCount + uCount) % MOD;
            eCountNew = (aCount + iCount) % MOD;
            iCountNew = (eCount + oCount) % MOD;
            oCountNew = (iCount) % MOD;
            uCountNew = (iCount + oCount) % MOD;
            aCount = aCountNew;
            eCount = eCountNew;
            iCount = iCountNew;
            oCount = oCountNew;
            uCount = uCountNew;
        }
        int result = (aCount + eCount + iCount + oCount + uCount)  % MOD;
        return result;
    }
};
```
