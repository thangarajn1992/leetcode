# Leetcode 537 Complex Number Multiplication

## Problem Statement

[https://leetcode.com/problems/complex-number-multiplication/](https://leetcode.com/problems/complex-number-multiplication/)

A complex number can be represented as a string on the form `"`**`real`**`+`**`imaginary`**`i"` where:

* `real` is the real part and is an integer in the range `[-100, 100]`.
* `imaginary` is the imaginary part and is an integer in the range `[-100, 100]`.
* `i2 == -1`.

Given two complex numbers `num1` and `num2` as strings, return _a string of the complex number that represents their multiplications_.

**Example 1:**

```text
Input: num1 = "1+1i", num2 = "1+1i"
Output: "0+2i"
Explanation: 
(1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
```

**Example 2:**

```text
Input: num1 = "1+-1i", num2 = "1+-1i"
Output: "0+-2i"
Explanation: 
(1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
```

**Constraints:**

* `num1` and `num2` are valid complex numbers.

### Solution

```cpp
class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        int real1, real2, imaginary1, imaginary2;

        sscanf(num1.c_str(), "%d+%di", &real1, &imaginary1);
        sscanf(num2.c_str(), "%d+%di", &real2, &imaginary2);
                
        int ans_real = (real1 * real2) - (imaginary1 * imaginary2);
        int ans_imaginary = (real1 * imaginary2) + (real2 * imaginary1);
        
        return to_string(ans_real) + '+' + to_string(ans_imaginary) + 'i';
    }
};
```



