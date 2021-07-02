# Leetcode 890 Find and Replace Pattern

## Problem Statement

[https://leetcode.com/problems/find-and-replace-pattern/](https://leetcode.com/problems/find-and-replace-pattern/)

Given a list of strings `words` and a string `pattern`, return _a list of_ `words[i]` _that match_ `pattern`. You may return the answer in **any order**.

A word matches the pattern if there exists a permutation of letters `p` so that after replacing every letter `x` in the pattern with `p(x)`, we get the desired word.

Recall that a permutation of letters is a bijection from letters to letters: every letter maps to another letter, and no two letters map to the same letter.

**Example 1:**

```text
Input: words = ["abc","deq","mee","aqq","dkd","ccc"], pattern = "abb"
Output: ["mee","aqq"]
Explanation: 
"mee" matches the pattern because there is a permutation {a -> m, b -> e, ...}. 
"ccc" does not match the pattern because {a -> c, b -> c, ...} is not a permutation, 
since a and b map to the same letter.
```

**Example 2:**

```text
Input: words = ["a","b","c"], pattern = "a"
Output: ["a","b","c"]
```

**Constraints:**

* `1 <= pattern.length <= 20`
* `1 <= words.length <= 50`
* `words[i].length == pattern.length`
* `pattern` and `words[i]` are lowercase English letters.

## Solution

```cpp
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;
        map<char,char> pat;
        set<char> entry;
        for(int i = 0; i < words.size(); i++)
        {
            bool pattern_match = true;
            for(int j = 0; j < words[i].size(); j++)
            {
                if(!pat[pattern[j]])
                {
                    if(entry.count(words[i][j]))
                    {
                        pattern_match = false;
                        break;
                    }
                    pat[pattern[j]] = words[i][j];
                    entry.insert(words[i][j]);
                }
                else if(pat[pattern[j]] && pat[pattern[j]] != words[i][j])
                {
                    pattern_match = false;
                    break;
                }
            }
            if(pattern_match) result.push_back(words[i]);
            pat.clear();
            entry.clear();         
        }
        return result;
    }
};
```

