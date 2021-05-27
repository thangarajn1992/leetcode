# Leetcode 38  Count and Say

## Problem Statement

[https://leetcode.com/problems/count-and-say/](https://leetcode.com/problems/count-and-say/)

The **count-and-say** sequence is a sequence of digit strings defined by the recursive formula:

* `countAndSay(1) = "1"`
* `countAndSay(n)` is the way you would "say" the digit string from `countAndSay(n-1)`, which is then converted into a different digit string.

To determine how you "say" a digit string, split it into the **minimal** number of groups so that each group is a contiguous section all of the **same character.** Then for each group, say the number of characters, then say the character. To convert the saying into a digit string, replace the counts with a number and concatenate every saying.

For example, the saying and conversion for digit string `"3322251"`: ![](https://assets.leetcode.com/uploads/2020/10/23/countandsay.jpg)

Given a positive integer `n`, return _the_ `nth` _term of the **count-and-say** sequence_.

**Example 1:**

```text
Input: n = 1
Output: "1"
Explanation: 
This is the base case.
```

**Example 2:**

```text
Input: n = 4
Output: "1211"
Explanation:
countAndSay(1) = "1"
countAndSay(2) = say "1" = one 1 = "11"
countAndSay(3) = say "11" = two 1's = "21"
countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
```

**Constraints:**

* `1 <= n <= 30`

## Solution

```cpp
class Solution {
public:
    string countAndSay(int n) {
        string ret = "11";
        if(n==1)
            return "1";
        if(n==2)
            return "11";
        for(int i = 3; i <= n; i++)
        {
            int len = ret.size();
            string temp = "";
            int count = 1;
            for(int j = 1; j < len; j++)
            {
                if(ret[j] == ret[j-1])
                {
                    count++;
                    continue;
                }
                temp += '0' + count;
                temp += ret[j-1];
                count = 1;
            }
            temp += '0' + count;
            temp += ret[len-1];
            ret = temp;
        }
        return ret;
    }
};
```

