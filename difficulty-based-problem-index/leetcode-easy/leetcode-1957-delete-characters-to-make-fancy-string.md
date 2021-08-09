# Leetcode 1957 Delete Characters to Make Fancy String

## Problem Statement

[https://leetcode.com/problems/delete-characters-to-make-fancy-string/](https://leetcode.com/problems/delete-characters-to-make-fancy-string/)

A **fancy string** is a string where no **three** **consecutive** characters are equal.

Given a string `s`, delete the **minimum** possible number of characters from `s` to make it **fancy**.

Return _the final string after the deletion_. It can be shown that the answer will always be **unique**.

**Example 1:**

```text
Input: s = "leeetcode"
Output: "leetcode"
Explanation:
Remove an 'e' from the first group of 'e's to create "leetcode".
No three consecutive characters are equal, so return "leetcode".
```

**Example 2:**

```text
Input: s = "aaabaaaa"
Output: "aabaa"
Explanation:
Remove an 'a' from the first group of 'a's to create "aabaaaa".
Remove two 'a's from the second group of 'a's to create "aabaa".
No three consecutive characters are equal, so return "aabaa".
```

**Example 3:**

```text
Input: s = "aab"
Output: "aab"
Explanation: No three consecutive characters are equal, so return "aab".
```

**Constraints:**

* `1 <= s.length <= 10^5`
* `s` consists only of lowercase English letters.

## Solution

```cpp
class Solution {
public:
    string makeFancyString(string s) {
        string ans;
        int count = 0;
        for(char c : s){
            if(count < 2 || ans[count-1] != c || ans[count-2] != c){
                ans.push_back(c);
                count++;
            }
        }
        return ans;
    }
};
```

