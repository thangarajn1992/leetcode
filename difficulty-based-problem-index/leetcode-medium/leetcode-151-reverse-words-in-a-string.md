# Leetcode 151 Reverse Words in a String

## Problem Statement

Given an input string `s`, reverse the order of the **words**.

A **word** is defined as a sequence of non-space characters. The **words** in `s` will be separated by at least one space.

Return _a string of the words in reverse order concatenated by a single space._

**Note** that `s` may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

**Example 1:**

```
Input: s = "the sky is blue"
Output: "blue is sky the"
```

**Example 2:**

```
Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.
```

**Example 3:**

```
Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
```

**Example 4:**

```
Input: s = "  Bob    Loves  Alice   "
Output: "Alice Loves Bob"
```

**Example 5:**

```
Input: s = "Alice does not even like bob"
Output: "bob like even not does Alice"
```

**Constraints:**

* `1 <= s.length <= 10^4`
* `s` contains English letters (upper-case and lower-case), digits, and spaces `' '`.
* There is **at least one** word in `s`.

**Follow-up: **If the string data type is mutable in your language, can you solve it **in-place** with `O(1)` extra space?

## Solution

### My Initial Solution

```cpp
class Solution {
public:
    string reverseWords(string s) {
        int index = 0;
        string result;
        while(index < s.size())
        {
            string currentString = "";
            
            // leading spaces
            while(index < s.size() && s[index] == ' ')
                index++;
            
            while(index < s.size() && s[index] != ' ')
            {
                currentString += s[index];
                index++;
            }
            if(currentString.size() > 0) // we have new word
            {
                if(result.size()) // except first word, add space for other words
                    currentString += ' ';
                
                // Add new word in the front
                result = currentString + result;
            }
        }
        return result;
    }
};
```
