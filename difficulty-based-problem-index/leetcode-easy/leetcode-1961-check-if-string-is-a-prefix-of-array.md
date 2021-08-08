# Leetcode 1961 Check If String Is a Prefix of Array

## Problem Statement

[https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/](https://leetcode.com/problems/check-if-string-is-a-prefix-of-array/)

Given a string `s` and an array of strings `words`, determine whether `s` is a **prefix string** of `words`.

A string `s` is a **prefix string** of `words` if `s` can be made by concatenating the first `k` strings in `words` for some **positive** `k` no larger than `words.length`.

Return `true` _if_ `s` _is a **prefix string** of_ `words`_, or_ `false` _otherwise_.

**Example 1:**

```text
Input: s = "iloveleetcode", words = ["i","love","leetcode","apples"]
Output: true
Explanation:
s can be made by concatenating "i", "love", and "leetcode" together.
```

**Example 2:**

```text
Input: s = "iloveleetcode", words = ["apples","i","love","leetcode"]
Output: false
Explanation:
It is impossible to make s using a prefix of arr.
```

**Constraints:**

* `1 <= words.length <= 100`
* `1 <= words[i].length <= 20`
* `1 <= s.length <= 1000`
* `words[i]` and `s` consist of only lowercase English letters.

## Solution

```cpp
class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int s_size = s.size(), w_size = words.size();
        int words_index = 0;
        int cur_char = 0;
        while(cur_char < s_size && words_index < w_size) 
        {
            int index;
            for(index = 0; index < words[words_index].size() && cur_char < s_size; index++)
            {
                if(s[cur_char] != words[words_index][index])
                    return false;
                cur_char++;
            }
            if(index != words[words_index].size())
                return false;
            words_index++;
        }
        return cur_char == s_size;
    }
};
```

