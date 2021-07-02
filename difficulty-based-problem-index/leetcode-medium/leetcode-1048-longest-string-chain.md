# Leetcode 1048 Longest String Chain

## Problem Statement

[https://leetcode.com/problems/longest-string-chain/](https://leetcode.com/problems/longest-string-chain/)

Given a list of words, each word consists of English lowercase letters.

Let's say `word1` is a predecessor of `word2` if and only if we can add exactly one letter anywhere in `word1` to make it equal to `word2`. For example, `"abc"` is a predecessor of `"abac"`.

A _word chain_ is a sequence of words `[word_1, word_2, ..., word_k]` with `k >= 1`, where `word_1` is a predecessor of `word_2`, `word_2` is a predecessor of `word_3`, and so on.

Return the longest possible length of a word chain with words chosen from the given list of `words`.

**Example 1:**

```text
Input: words = ["a","b","ba","bca","bda","bdca"]
Output: 4
Explanation: 
One of the longest word chain is "a","ba","bda","bdca".
```

**Example 2:**

```text
Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
Output: 5
```

**Constraints:**

* `1 <= words.length <= 1000`
* `1 <= words[i].length <= 16`
* `words[i]` only consists of English lowercase letters.

## Solution

```cpp
class Solution {
public:
    using psi = pair<string,int>;
    int longestStrChain(vector<string>& words) {
        vector<psi> ws_by_length[17];
        int result = 1;
        
        for( auto &w : words)
            ws_by_length[w.size()].emplace_back(move(w),1);
        
        for(int i = 2; i <= 16; i++)
        {
            for(auto& [target, target_depth] : ws_by_length[i])
            {
                for(const auto& [source, source_depth] : ws_by_length[i-1])
                {
                    if(predecessor(source, target))
                    {
                        target_depth = max(target_depth, 1 + source_depth);
                        result = max(result, target_depth);
                    }
                }
            }
        }
        return result;
    }
    
    bool predecessor(const string &from, const string &to)
    {
        int f = 0, t = 0;
        while(f < from.size() && t < to.size())
        {
            if(from[f] == to[t])
                f++, t++;
            else
            {
                t++;
                if(t - f >= 2)
                    return false;
            }
        }
        return true;
    }
};
```

