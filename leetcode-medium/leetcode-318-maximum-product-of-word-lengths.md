# Leetcode 318 Maximum Product of Word Lengths

## Problem Statement

[https://leetcode.com/problems/maximum-product-of-word-lengths/](https://leetcode.com/problems/maximum-product-of-word-lengths/)

Given a string array `words`, return _the maximum value of_ `length(word[i]) * length(word[j])` _where the two words do not share common letters_. If no such two words exist, return `0`.

**Example 1:**

```text
Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16
Explanation: The two words can be "abcw", "xtfn".
```

**Example 2:**

```text
Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
Output: 4
Explanation: The two words can be "ab", "cd".
```

**Example 3:**

```text
Input: words = ["a","aa","aaa","aaaa"]
Output: 0
Explanation: No such pair of words.
```

**Constraints:**

* `2 <= words.length <= 1000`
* `1 <= words[i].length <= 1000`
* `words[i]` consists only of lowercase English letters.

## Solution

```cpp
class Solution {
public:
    // 0x3FFFFFF means we have already seen all characters
    // No need to proceed for other characters in string ( max len 1000)
    int maxProduct(vector<string>& words) {
        vector<int> ap(words.size(),0);
        for(int i = 0; i < words.size(); i++)
            for(int j = 0; j < words[i].size() && ap[i] != 0x3FFFFFF; j++)
                if( ((ap[i] >> (words[i][j] - 'a')) & 1) == 0)
                    ap[i] |= 1 << (words[i][j] - 'a');
        
        int result = 0;
        for(int i = 0; i < ap.size(); i++)
            for(int j = i+1; j < ap.size(); j++)
                if(!(ap[i]&ap[j]))
                   result = max(result, int(words[i].size() * words[j].size()));
        
        return result;
    }
};
```

