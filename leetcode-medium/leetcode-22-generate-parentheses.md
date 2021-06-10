# Leetcode 22 Generate Parentheses

## Problem Statement

[https://leetcode.com/problems/generate-parentheses/](https://leetcode.com/problems/generate-parentheses/)

Given `n` pairs of parentheses, write a function to _generate all combinations of well-formed parentheses_.

**Example 1:**

```text
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
```

**Example 2:**

```text
Input: n = 1
Output: ["()"]
```

**Constraints:**

* `1 <= n <= 8`

## Solution

```cpp
class Solution {
public:
    vector<string> result;
    void genParUtil(string &out, int open, int close, int n)
    {
        if(open == close && open == n){
            result.push_back(out);
            return;
        }
        if(open < n)
        {
            out += "(";
            genParUtil(out, open+1, close, n);
            out.pop_back();
        }
        if(close < open)
        {
            out += ")";
            genParUtil(out, open, close+1, n);
            out.pop_back();
        }         
    }
    vector<string> generateParenthesis(int n) {
        string out;
        genParUtil(out, 0, 0, n);
        return result;
    }
};
```

