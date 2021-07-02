# Leetcode 14 Longest Common Prefix

[https://leetcode.com/problems/longest-common-prefix/](https://leetcode.com/problems/longest-common-prefix/)

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string `""`.

**Example 1:**

```text
Input: strs = ["flower","flow","flight"]
Output: "fl"
```

**Example 2:**

```text
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: 
There is no common prefix among the input strings.
```

**Constraints:**

* `1 <= strs.length <= 200`
* `0 <= strs[i].length <= 200`
* `strs[i]` consists of only lower-case English letters.

## Solution

### Vertical Comparison Approach

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1)
            return strs[0];
        for(int i = 0; i < strs[0].size(); i++)
        {
            char c = strs[0][i];
            for(int j = 1; j < strs.size(); j++)
                if(i == strs[j].size() || strs[j][i] != c)
                    return strs[0].substr(0,i); // substr(index, len)
        }
        return strs[0];
    }
};
```

### Sorting and Comparing Low and High 

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s = "";
        sort(strs.begin(), strs.end());
        string s1 = strs[0];
        string s2 = strs[strs.size()-1];
        for(int i = 0; i < min(s1.size(),s2.size()); i++)
        {
            if(s1[i] == s2[i])
                s += s1[i];
            else 
                break;
        }
        return s;
    }
};
```

