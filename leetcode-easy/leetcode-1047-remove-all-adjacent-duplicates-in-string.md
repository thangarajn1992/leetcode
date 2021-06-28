# Leetcode 1047 Remove All Adjacent Duplicates In String

## Problem Statement

[https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/](https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/)

You are given a string `s` consisting of lowercase English letters. A **duplicate removal** consists of choosing two **adjacent** and **equal** letters and removing them.

We repeatedly make **duplicate removals** on `s` until we no longer can.

Return _the final string after all such duplicate removals have been made_. It can be proven that the answer is **unique**.

**Example 1:**

```text
Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal,
and this is the only possible move.  The result of this move is that the string is "aaca", 
of which only "aa" is possible, so the final string is "ca".
```

**Example 2:**

```text
Input: s = "azxxzy"
Output: "ay"
```

**Constraints:**

* `1 <= s.length <= 10^5`
* `s` consists of lowercase English letters.

## Solution

### Stack Approach

```cpp
class Solution {
public:
    string removeDuplicates(string s) {
        string str = "";
        for(char c : s)
        {  
            if(!str.empty())
            {
                if(str.back() == c)
                    str.pop_back();
                else
                    str.push_back(c);
            }
            else
                str.push_back(c);
        }
        return str;
    }
};
```



