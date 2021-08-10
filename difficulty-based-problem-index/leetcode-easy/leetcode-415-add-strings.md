# Leetcode 415 Add Strings

## Problem Statement

[https://leetcode.com/problems/add-strings/](https://leetcode.com/problems/add-strings/)

Given two non-negative integers, `num1` and `num2` represented as string, return _the sum of_ `num1` _and_ `num2` _as a string_.

You must solve the problem without using any built-in library for handling large integers \(such as `BigInteger`\). You must also not convert the inputs to integers directly.

**Example 1:**

```text
Input: num1 = "11", num2 = "123"
Output: "134"
```

**Example 2:**

```text
Input: num1 = "456", num2 = "77"
Output: "533"
```

**Example 3:**

```text
Input: num1 = "0", num2 = "0"
Output: "0"
```

**Constraints:**

* `1 <= num1.length, num2.length <= 10^4`
* `num1` and `num2` consist of only digits.
* `num1` and `num2` don't have any leading zeros except for the zero itself.

## Solution

```cpp
class Solution {
public:
    string addStrings(string num1, string num2) {
        int num1_size = num1.size();
        int num2_size = num2.size();
        string result;
        int n1_index = num1_size - 1;
        int n2_index = num2_size - 1;
        int n3_index;
        
        // Copy the longest string to result and set its index
        if(num1_size >= num2_size)
        {
            result = num1;
            n3_index = n1_index;
        }
        else
        {
            result = num2;
            n3_index = n2_index;
        }
        
        int carry_in = 0;
        
        // Add till the common digits
        while(n1_index >= 0 && n2_index >= 0)
        {
            int sum = num1[n1_index--] - '0' + num2[n2_index--] - '0' + carry_in;
            carry_in = sum / 10;
            result[n3_index--] = sum % 10 + '0';
        }
        
        // If longer string has extra digits and we have a carry-in
        // update the corresponding digits.
        while(carry_in && n3_index >= 0)
        {
            int num = result[n3_index] - '0' + carry_in;
            carry_in = num / 10;
            result[n3_index--] = num % 10 + '0';
        }
        
        // After processing all digits, if carry is there insert at beginning
        if(carry_in)
            result.insert(result.begin(), carry_in + '0');
        
        return result;
    }
};
```

