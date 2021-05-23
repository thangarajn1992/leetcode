# Leetcode 1871 Jump Game VII

## Problem Statement

[https://leetcode.com/problems/jump-game-vii/](https://leetcode.com/problems/jump-game-vii/)

You are given a **0-indexed** binary string `s` and two integers `minJump` and `maxJump`. In the beginning, you are standing at index `0`, which is equal to `'0'`. You can move from index `i` to index `j` if the following conditions are fulfilled:

* `i + minJump <= j <= min(i + maxJump, s.length - 1)`, and
* `s[j] == '0'`.

Return `true` if you can reach index `s.length - 1` in `s`_, or_ `false` _otherwise._

**Example 1:**

```text
Input: s = "011010", minJump = 2, maxJump = 3
Output: true
Explanation:
In the first step, move from index 0 to index 3. 
In the second step, move from index 3 to index 5.
```

**Example 2:**

```text
Input: s = "01101110", minJump = 2, maxJump = 3
Output: false
```

**Constraints:**

* `2 <= s.length <= 10^5`
* `s[i]` is either `'0'` or `'1'`.
* `s[0] == '0'`
* `1 <= minJump <= maxJump < s.length`

## Solution

### Simple and without DP

```cpp
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<int> idx;
        idx.push_back(0);
        for (int i = 1; i < n; i++)
        {
            if (s[i]=='0')
            {
                // Start searching from the last reachable 0 to 
                // decrease time complexity
                for (int j = idx.size()-1; j >= 0; j--) 
                {
                    if (idx[j] + minJump <= i && idx[j] + maxJump >= i)
                    {
                        idx.push_back(i);
                        break;
                    }
                }
            }
        }
        return idx.back() == n-1;  
    }
};
```

### DP \| Memoization approach

```cpp
class Solution {
public:
    vector<int> dp;
    bool helper(int curr, int& minJump, int& maxJump, string& s) {
        if(curr == s.size() - 1) 
            return true;
        
        if(dp[curr] != -1) 
            return dp[curr];
        
        for(int next = curr + minJump ; 
            next <= curr + maxJump and next < s.size(); 
            next++) 
        {
            if(s[next] == '0') {
                if(dp[next] != -1) {  // Yet to confirm this part for all testcases
                    return dp[curr] = dp[next];
                } else if(helper(next, minJump, maxJump, s)){ 
                    return dp[curr] = 1;
                }
            }  
        }
        return dp[curr] = 0; 
    }
    
    bool canReach(string s, int minJump, int maxJump) {
        if(s[s.size()-1] != '0') 
            return false;        
        dp = vector<int>(s.size(), -1);
        return helper(0, minJump, maxJump, s);
    }
};
```

