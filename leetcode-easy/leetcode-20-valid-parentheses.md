# Leetcode 20 Valid Parentheses

## Problem Statement

[https://leetcode.com/problems/valid-parentheses/](https://leetcode.com/problems/valid-parentheses/)

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.

**Example 1:**

```text
Input: s = "()"
Output: true
```

**Example 2:**

```text
Input: s = "()[]{}"
Output: true
```

**Example 3:**

```text
Input: s = "(]"
Output: false
```

**Example 4:**

```text
Input: s = "([)]"
Output: false
```

**Example 5:**

```text
Input: s = "{[]}"
Output: true
```

**Constraints:**

* `1 <= s.length <= 10^4`
* `s` consists of parentheses only `'()[]{}'`.

## Solution

```cpp
class Solution {
public:
    bool isValid(string s) {
        stack<char> bracket;
        for(char c : s)
        {
            switch(c)
            {
                case '{':
                case '[':
                case '(':
                    bracket.push(c);
                    break;
                case '}':
                    if(bracket.empty() || bracket.top() != '{')
                       return false;
                    bracket.pop();
                    break;
                case ']':
                    if(bracket.empty() || bracket.top() != '[')
                       return false;
                    bracket.pop();
                    break;
                case ')':
                    if(bracket.empty() || bracket.top() != '(')
                       return false;
                    bracket.pop();
                    break;
            }
        }  
        return bracket.empty();
    }
};
```

