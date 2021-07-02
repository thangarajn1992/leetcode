# Leetcode 17  Letter Combinations of a Phone Number

## Problem Statement

[https://leetcode.com/problems/letter-combinations-of-a-phone-number/](https://leetcode.com/problems/letter-combinations-of-a-phone-number/)

Given a string containing digits from `2-9` inclusive, return all possible letter combinations that the number could represent. Return the answer in **any order**.

A mapping of digit to letters \(just like on the telephone buttons\) is given below. Note that 1 does not map to any letters.

![](https://upload.wikimedia.org/wikipedia/commons/thumb/7/73/Telephone-keypad2.svg/200px-Telephone-keypad2.svg.png)

**Example 1:**

```text
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
```

**Example 2:**

```text
Input: digits = ""
Output: []
```

**Example 3:**

```text
Input: digits = "2"
Output: ["a","b","c"]
```

**Constraints:**

* `0 <= digits.length <= 4`
* `digits[i]` is a digit in the range `['2', '9']`.

## Solution

```cpp
class Solution {
public:
    string arr[10] = {"","","abc","def","ghi","jkl","mno","pqrs",
                     "tuv","wxyz"};
    
    void letters(string digits, string out, vector<string>& output){
        if(digits.empty()){
            output.push_back(out);
            return;
        }
        string s = arr[digits[0]-'0'];
        for(int i=0; i<s.length(); i++){
            letters(digits.substr(1), out+s[i], output);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        vector<string> output;
        letters(digits ,"" , output);
        return output;
    }
};
```

