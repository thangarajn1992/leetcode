# Leetcode 1945 Sum of Digits of String After Convert

## Problem Statement

[https://leetcode.com/problems/sum-of-digits-of-string-after-convert/](https://leetcode.com/problems/sum-of-digits-of-string-after-convert/)

You are given a string `s` consisting of lowercase English letters, and an integer `k`.

First, **convert** `s` into an integer by replacing each letter with its position in the alphabet \(i.e., replace `'a'` with `1`, `'b'` with `2`, ..., `'z'` with `26`\). Then, **transform** the integer by replacing it with the **sum of its digits**. Repeat the **transform** operation `k` **times** in total.

For example, if `s = "zbax"` and `k = 2`, then the resulting integer would be `8` by the following operations:

* **Convert**: `"zbax" ➝ "(26)(2)(1)(24)" ➝ "262124" ➝ 262124`
* **Transform \#1**: `262124 ➝ 2 + 6 + 2 + 1 + 2 + 4 ➝ 17`
* **Transform \#2**: `17 ➝ 1 + 7 ➝ 8`

Return _the resulting integer after performing the operations described above_.

**Example 1:**

```text
Input: s = "iiii", k = 1
Output: 36
Explanation: The operations are as follows:
- Convert: "iiii" ➝ "(9)(9)(9)(9)" ➝ "9999" ➝ 9999
- Transform #1: 9999 ➝ 9 + 9 + 9 + 9 ➝ 36
Thus the resulting integer is 36.
```

**Example 2:**

```text
Input: s = "leetcode", k = 2
Output: 6
Explanation: The operations are as follows:
- Convert: "leetcode" ➝ "(12)(5)(5)(20)(3)(15)(4)(5)" ➝ "12552031545" ➝ 12552031545
- Transform #1: 12552031545 ➝ 1 + 2 + 5 + 5 + 2 + 0 + 3 + 1 + 5 + 4 + 5 ➝ 33
- Transform #2: 33 ➝ 3 + 3 ➝ 6
Thus the resulting integer is 6.
```

**Example 3:**

```text
Input: s = "zbax", k = 2
Output: 8
```

**Constraints:**

* `1 <= s.length <= 100`
* `1 <= k <= 10`
* `s` consists of lowercase English letters.

## Solution

### My Code

```cpp
class Solution {
public:
    int getLucky(string s, int k) {
        int value = 0;
        string r;
        for(char c : s)
            r += to_string(c - 'a' + 1);
        
        while(k > 0)
        {
            value = 0;
            for(char c : r)
                value += (c - '0');          
            r = to_string(value);
            k--;
        }
        return value;
    }
};
```

