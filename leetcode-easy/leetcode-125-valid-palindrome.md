# Leetcode 125 Valid Palindrome

## Problem Statement

[https://leetcode.com/problems/valid-palindrome/](https://leetcode.com/problems/valid-palindrome/)

Given a string `s`, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

**Example 1:**

```text
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
```

**Example 2:**

```text
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
```

**Constraints:**

* `1 <= s.length <= 2 * 10^5`
* `s` consists only of printable ASCII characters.

## Solution

```cpp
class Solution {
public:
    bool isPalindrome(string s) {
        int low = 0, high = s.size()-1;
        while(low < high)
        {
            if(!isalnum(s[low]))
            {
                low++;
                continue;
            }
            if(!isalnum(s[high])){
                high--;
                continue;
            }
            if(tolower(s[low++]) != tolower(s[high--]))
                return false;
        }
        return true;
    }
};
```

