# Leetcode 1239 Maximum Length of a Concatenated String with Unique Characters

## Problem Statement

Given an array of strings `arr`. String `s` is a concatenation of a sub-sequence of `arr` which have **unique characters**.

Return _the maximum possible length_ of `s`.

**Example 1:**

```text
Input: arr = ["un","iq","ue"]
Output: 4
Explanation: 
All possible concatenations are "","un","iq","ue","uniq" and "ique".
Maximum length is 4.
```

**Example 2:**

```text
Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: 
Possible solutions are "chaers" and "acters".
```

**Example 3:**

```text
Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
```

**Constraints:**

* `1 <= arr.length <= 16`
* `1 <= arr[i].length <= 26`
* `arr[i]` contains only lower case English letters.

## Solution

```cpp
class Solution {
public:
    int solve(vector<string> &v,int low,bitset<26> bits=0,string s="")
    {
        if(low==v.size()) return s.size();  //base case
        bitset<26> b{bits};
        for(auto &i: v[low])
        {
            if(b[i-'a']==1)   // character is already in the string 
                return solve(v,low+1,bits,s);  //backtracking step
            b[i-'a']=1;  //updating our mask
        }
        // if the string is valid and it didnt fall into backtracking step 
        // then we have to check both choices and return the max value we get
        return max(solve(v, low+1, b, s+v[low]), solve(v, low+1, bits, s)); 
    }
    int maxLength(vector<string>& arr) {
       return solve(arr,0);
    }
};
```

