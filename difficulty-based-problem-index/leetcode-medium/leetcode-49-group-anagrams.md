# Leetcode 49 Group Anagrams

## Problem Statement

[https://leetcode.com/problems/group-anagrams/](https://leetcode.com/problems/group-anagrams/)

Given an array of strings `strs`, group **the anagrams** together. You can return the answer in **any order**.

An **Anagram** is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

**Example 1:**

```text
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
```

**Example 2:**

```text
Input: strs = [""]
Output: [[""]]
```

**Example 3:**

```text
Input: strs = ["a"]
Output: [["a"]]
```

**Constraints:**

* `1 <= strs.length <= 10^4`
* `0 <= strs[i].length <= 100`
* `strs[i]` consists of lower-case English letters.

## Solution

```cpp
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string, int> m;  
        for(auto &str : strs)
        {
            string loc = str;
            sort(loc.begin(), loc.end());
            if(!m.count(loc)){
               m[loc] = result.size();
               result.push_back({str}); 
            }
            else
                result[m[loc]].push_back(str);
        }
        return result;
    }
};
```

