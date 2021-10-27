# Leetcode 906 Super Palindromes

[Explanation](leetcode-906-super-palindromes.md#explanation)             [Solution](leetcode-906-super-palindromes.md#solution)

## Problem Statement

[https://leetcode.com/problems/super-palindromes/](https://leetcode.com/problems/super-palindromes/)

Let's say a positive integer is a **super-palindrome** if it is a palindrome, and it is also the square of a palindrome.

Given two positive integers `left` and `right` represented as strings, return _the number of **super-palindromes** integers in the inclusive range_ `[left, right]`.

**Example 1:**

```
Input: left = "4", right = "1000"
Output: 4
Explanation: 
4, 9, 121, and 484 are superpalindromes.
Note that 676 is not a superpalindrome: 26 * 26 = 676, but 26 is not a palindrome.
```

**Example 2:**

```
Input: left = "1", right = "2"
Output: 1
```

**Constraints:**

* `1 <= left.length, right.length <= 18`
* `left` and `right` consist of only digits.
* `left` and `right` cannot have leading zeros.
* `left` and `right` represent integers in the range `[1, 10^18]`.
* `left` is less than or equal to `right`.

## Explanation

**Intuition**

Say `P = R^2 ` is a superpalindrome.

Because R is a palindrome, the first half of the digits in R  determine R' up to two possibilities. We can iterate through these digits: let k be the first half of the digits in R. For example, if k=1234, then R=1234321 or R=12344321. Each possibility has either an odd or an even number of digits in R .

Notice because P < 10^18 , R< (10^18)^(1/2) ​=10^9, andR=k∣k′ (concatenation), where k′  is k reversed (and also possibly truncated by one digit); so that k<10^ 5 = MAGIC, our magic constant.

**Algorithm**

For each1 ≤ k< MAGIC, let's create the associated palindrome R, and check whether R^2 is a palindrome.

We should handle the odd and even possibilities separately, as we would like to break early so as not to do extra work.

To check whether an integer is a palindrome, we could check whether it is equal to its reverse. To create the reverse of an integer, we can do it digit by digit.

## Solution

```cpp
class Solution {
public:
    int superpalindromesInRange(string left, string right) {
        long L = stoll(left);
        long R = stoll(right);
        int MAGIC = 100000;
        int ans = 0;

        // count odd length;
        for (int k = 1; k < MAGIC; ++k) {
            string sb = to_string(k);
            for (int i = sb.length() - 2; i >= 0; --i)
                sb += sb[i];
            long v = stoll(sb);
            v *= v;
            if (v > R) break;
            if (v >= L && isPalindrome(v))
                ans++;
        }

        // count even length;
        for (int k = 1; k < MAGIC; ++k) {
            string sb = to_string(k);
            for (int i = sb.length() - 1; i >= 0; --i)
                sb += sb[i];
            long v = stoll(sb);
            v *= v;
            if (v > R) break;
            if (v >= L && isPalindrome(v)) 
                ans++;
        }
        return ans;
    }

    bool isPalindrome(long x) {
        return x == reverse(x);
    }

    long reverse(long x) {
        long ans = 0;
        while (x > 0) {
            ans = 10 * ans + x % 10;
            x /= 10;
        }
        return ans;
    }
};
```
