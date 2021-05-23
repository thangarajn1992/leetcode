# Leetcode 1869 Longer Contiguous Segments of Ones than Zeros

## Problem Statement

[https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/](https://leetcode.com/problems/longer-contiguous-segments-of-ones-than-zeros/)

Given a binary string `s`, return `true` _if the **longest** contiguous segment of_ `1`_s is **strictly longer** than the **longest** contiguous segment of_ `0`_s in_ `s`. Return `false` _otherwise_.

* For example, in `s = "110100010"` the longest contiguous segment of `1`s has length `2`, and the longest contiguous segment of `0`s has length `3`.

Note that if there are no `0`s, then the longest contiguous segment of `0`s is considered to have length `0`. The same applies if there are no `1`s.

**Example 1:**

```text
Input: s = "1101"
Output: true
Explanation:
The longest contiguous segment of 1s has length 2: "1101"
The longest contiguous segment of 0s has length 1: "1101"
The segment of 1s is longer, so return true.
```

**Example 2:**

```text
Input: s = "111000"
Output: false
Explanation:
The longest contiguous segment of 1s has length 3: "111000"
The longest contiguous segment of 0s has length 3: "111000"
The segment of 1s is not longer, so return false.
```

**Example 3:**

```text
Input: s = "110100010"
Output: false
Explanation:
The longest contiguous segment of 1s has length 2: "110100010"
The longest contiguous segment of 0s has length 3: "110100010"
The segment of 1s is not longer, so return false.
```

**Constraints:**

* `1 <= s.length <= 100`
* `s[i]` is either `'0'` or `'1'`.

## Solution

```cpp
class Solution {
public:
    bool checkZeroOnes(string s) {
        int max_0 = 0, max_1 = 0;
        int curr = 1;
        for(int i = 1; i < s.size(); i++)
        {
            if(s[i] == s[i-1])
                curr++;
            else
            {
                if(s[i-1] == '0')
                    max_0 = max(max_0, curr);
                else
                    max_1 = max(max_1, curr);
                curr = 1;
            }
        }
        if(s[s.size()-1] == '1') max_1 = max(max_1, curr);
        else max_0 = max(max_0, curr);
        return max_1 > max_0;
    }
};
```



