# Leetcode 792  Number of Matching Subsequences

## Problem Statement

[https://leetcode.com/problems/number-of-matching-subsequences/](https://leetcode.com/problems/number-of-matching-subsequences/)

Given a string `s` and an array of strings `words`, return _the number of_ `words[i]` _that is a subsequence of_ `s`.

A **subsequence** of a string is a new string generated from the original string with some characters \(can be none\) deleted without changing the relative order of the remaining characters.

* For example, `"ace"` is a subsequence of `"abcde"`.

**Example 1:**

```text
Input: s = "abcde", words = ["a","bb","acd","ace"]
Output: 3
Explanation: 
There are three strings in words that are a subsequence of s: 
"a", "acd", "ace".
```

**Example 2:**

```text
Input: s = "dsahjpjauf", words = ["ahjpjau","ja","ahbwzgqnuk","tnmlanowax"]
Output: 2
```

**Constraints:**

* `1 <= s.length <= 5 * 10^4`
* `1 <= words.length <= 5000`
* `1 <= words[i].length <= 50`
* `s` and `words[i]` consist of only lowercase English letters.

## Solution

### My solution

```cpp
class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> indices(26);
        for(int i = 0; i < s.size(); i++)
            indices[s[i] - 'a'].push_back(i);
        
        int result = 0;
        for(int i = 0; i < words.size(); i++)
        {
            int prev = -1;
            bool found = true;
            vector<int> cur_index(26, 0);
            for(char &c: words[i])
            {
                int index;
                for(index = cur_index[c-'a'];
                    index < indices[c-'a'].size() &&
                    indices[c-'a'][index] <= prev;
                    index++);

                if(index == indices[c-'a'].size())
                {
                    found = false;
                    break;
                }
                else
                {
                    cur_index[c-'a'] = index;
                    prev = indices[c-'a'][index];
                }
            }
            if(found == true)
                result++;
        }
        return result;
    }
};
```

