# Leetcode 557 Reverse Words in a String III

## Problem Statement

[https://leetcode.com/problems/reverse-words-in-a-string-iii/](https://leetcode.com/problems/reverse-words-in-a-string-iii/)

Given a string `s`, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

**Example 1:**

```text
Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"
```

**Example 2:**

```text
Input: s = "God Ding"
Output: "doG gniD"
```

**Constraints:**

* `1 <= s.length <= 5 * 10^4`
* `s` contains printable **ASCII** characters.
* `s` does not contain any leading or trailing spaces.
* There is **at least one** word in `s`.
* All the words in `s` are separated by a single space.

## Solution

```cpp
class Solution {
public:
    string reverseWords(string s) {
        int begin = 0, end = 0;
        int wordStart = 0, wordEnd = 0;
        char temp;
        int size = s.size();
        
        while(1)
        {
            if(end == size || s[end] == ' ') // One Word
            {
                if(end != begin) // single letter word dont need to reverse
                {
                    wordStart = begin, wordEnd = end-1;
                    while(wordStart < wordEnd)
                        swap(s[wordStart++], s[wordEnd--]);
                    
                    begin = end + 1;
                }
            }
            if(end == size)
                break;
            end++;
        }
        return s;
    }
};
```

