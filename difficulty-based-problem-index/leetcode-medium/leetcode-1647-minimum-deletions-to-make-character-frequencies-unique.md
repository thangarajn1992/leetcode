# Leetcode 1647 Minimum Deletions to Make Character Frequencies Unique

## Problem Statement

[https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/](https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/)



A string `s` is called **good** if there are no two different characters in `s` that have the same **frequency**.

Given a string `s`, return _the **minimum** number of characters you need to delete to make_ `s` _**good**._

The **frequency** of a character in a string is the number of times it appears in the string. For example, in the string `"aab"`, the **frequency** of `'a'` is `2`, while the **frequency** of `'b'` is `1`.

**Example 1:**

```text
Input: s = "aab"
Output: 0
Explanation: s is already good.
```

**Example 2:**

```text
Input: s = "aaabbbcc"
Output: 2
Explanation: You can delete two 'b's resulting in the good string "aaabcc".
Another way it to delete one 'b' and one 'c' resulting in the good string "aaabbc".
```

**Example 3:**

```text
Input: s = "ceabaacb"
Output: 2
Explanation: You can delete both 'c's resulting in the good string "eabaab".
Note that we only care about characters that are still in the string at the end (i.e. frequency of 0 is ignored).
```

**Constraints:**

* `1 <= s.length <= 10^5`
* `s` contains only lowercase English letters.

## Solution

```cpp
class Solution {
public:
    int minDeletions(string s) {
        vector<int> v(26,0);   // To store frequency
        vector<int> v2;  // To store repeated frequency
        set<int> ss;   // To store set of frequency
        
        for(auto i:s)
            v[i-'a']++;

        for(auto i:v)
        {
            if(ss.count(i) == 0)
                ss.insert(i);
            else
                v2.push_back(i);
        }
        
        int res=0;
        for(auto i:v2)
        {
            while(ss.count(i) == 1 and i > 0)
            {
                i--;
                res++;
            }
            ss.insert(i);
        }
        return res;
    }
};
```

