# Leetcode 1888 Minimum Number of Flips to Make the Binary String Alternating

## Problem Statement

[https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/](https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/)

You are given a binary string `s`. You are allowed to perform two types of operations on the string in any sequence:

* **Type-1: Remove** the character at the start of the string `s` and **append** it to the end of the string.
* **Type-2: Pick** any character in `s` and **flip** its value, i.e., if its value is `'0'` it becomes `'1'` and vice-versa.

Return _the **minimum** number of **type-2** operations you need to perform_ _such that_ `s` _becomes **alternating**._

The string is called **alternating** if no two adjacent characters are equal.

* For example, the strings `"010"` and `"1010"` are alternating, while the string `"0100"` is not.

**Example 1:**

```text
Input: s = "111000"
Output: 2
Explanation: 
Use the first operation two times to make s = "100011".
Then, use the second operation on the third and sixth elements to make s = "101010".
```

**Example 2:**

```text
Input: s = "010"
Output: 0
Explanation: 
The string is already alternating.
```

**Example 3:**

```text
Input: s = "1110"
Output: 1
Explanation: 
Use the second operation on the second element to make s = "1010".
```

**Constraints:**

* `1 <= s.length <= 10^5`
* `s[i]` is either `'0'` or `'1'`.

## Solution

```cpp
class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        s += s;  // To take care of Type-1 operation, we use sliding window.
        string s1, s2;
        
        for(int i = 0; i < s.size(); i++) {
            s1 += i % 2 ? '0' : '1';
            s2 += i % 2 ? '1' : '0';
        }
        int ans1 = 0, ans2 = 0, ans = INT_MAX;
        // ans1 is minimum difference (Type 2 operation) between the sliding window and s1
        // ans2 is minimum difference (Type 2 operation) between the sliding window and s2
        for(int i = 0; i < s.size(); i++) {
            if(s1[i] != s[i]) ++ans1;
            if(s2[i] != s[i]) ++ans2;
            if(i >= n) { 
            // Now the left most element is outside of sliding window, 
            // we need to subtract the ans if we did `flip` before.
                if(s1[i - n] != s[i - n]) --ans1;
                if(s2[i - n] != s[i - n]) --ans2;
            }
            if(i >= n - 1)
                ans = min({ans1, ans2, ans});
        }
        return ans;
    }
};
```

