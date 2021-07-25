# Leetcode 1941 Check if All Characters Have Equal Number of Occurrences

## Problem Statement

[https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/](https://leetcode.com/problems/check-if-all-characters-have-equal-number-of-occurrences/)

Given a string `s`, return `true` _if_ `s` _is a **good** string, or_ `false` _otherwise_.

A string `s` is **good** if **all** the characters that appear in `s` have the **same** number of occurrences \(i.e., the same frequency\).

**Example 1:**

```text
Input: s = "abacbc"
Output: true
Explanation: 
The characters that appear in s are 'a', 'b', and 'c'. All characters occur 2 times in s.
```

**Example 2:**

```text
Input: s = "aaabb"
Output: false
Explanation: 
The characters that appear in s are 'a' and 'b'.
'a' occurs 3 times while 'b' occurs 2 times, which is not the same number of times.
```

**Constraints:**

* `1 <= s.length <= 1000`
* `s` consists of lowercase English letters.

## Solution

```cpp
class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int> freq(26,0);
        for(char c: s)
            freq[c-'a']++;
        
        int freq_needed = 0;
        for(int &count : freq)
        {
            if(count)
            {    
                if(freq_needed == 0)
                    freq_needed = count;
                else if(count != freq_needed)
                    return false;
            }
        }    
        return true;
    }
};
```

