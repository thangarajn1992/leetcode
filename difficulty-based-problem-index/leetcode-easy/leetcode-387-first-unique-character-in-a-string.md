# Leetcode 387 First Unique Character in a String

## Problem Statement

[https://leetcode.com/problems/first-unique-character-in-a-string/](https://leetcode.com/problems/first-unique-character-in-a-string/)

Given a string `s`, return _the first non-repeating character in it and return its index_. If it does not exist, return `-1`.

**Example 1:**

```text
Input: s = "leetcode"
Output: 0
```

**Example 2:**

```text
Input: s = "loveleetcode"
Output: 2
```

**Example 3:**

```text
Input: s = "aabb"
Output: -1
```

**Constraints:**

* `1 <= s.length <= 10^5`
* `s` consists of only lowercase English letters.

## Solution

```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        int count[26] = {0};
        for(int i = 0; i < s.size(); i++)
                count[s[i] - 'a']++;
        for(int i = 0; i < s.size(); i++)
            if(count[s[i] - 'a'] == 1)
                return i;
        return -1;
    }
};
```

