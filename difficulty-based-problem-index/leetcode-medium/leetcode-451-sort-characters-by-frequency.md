# Leetcode 451 Sort Characters By Frequency

## Problem Statement

[https://leetcode.com/problems/sort-characters-by-frequency/](https://leetcode.com/problems/sort-characters-by-frequency/)

Given a string `s`, sort it in **decreasing order** based on the **frequency** of the characters. The **frequency** of a character is the number of times it appears in the string.

Return _the sorted string_. If there are multiple answers, return _any of them_.

**Example 1:**

```
Input: s = "tree"
Output: "eert"
Explanation: 
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
```

**Example 2:**

```
Input: s = "cccaaa"
Output: "aaaccc"
Explanation: 
Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.
Note that "cacaca" is incorrect, as the same characters must be together.
```

**Example 3:**

```
Input: s = "Aabb"
Output: "bbAa"
Explanation: 
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
```

&#x20;

**Constraints:**

* `1 <= s.length <= 5 * 10^5`
* `s` consists of uppercase and lowercase English letters and digits.

## Solution

```cpp
class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(256);
        for(char c : s)
            freq[c]++;
        
        map<int, string> bucket;
        for(int i = 0; i < 256; i++)
            if(freq[i] > 0)
                bucket[freq[i]].append(freq[i], i);
                                
        string result = "";
        auto it = bucket.rbegin();
        while(it != bucket.rend())
        {
            result.append(it->second);
            it++;
        }
        return result;
    }
};
```
