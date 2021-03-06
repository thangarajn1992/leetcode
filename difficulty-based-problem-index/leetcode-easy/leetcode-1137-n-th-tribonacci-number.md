# Leetcode 1137 N-th Tribonacci Number

## Problem Statement

[https://leetcode.com/problems/n-th-tribonacci-number/](https://leetcode.com/problems/n-th-tribonacci-number/)

The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n &gt;= 0.

Given `n`, return the value of Tn.

**Example 1:**

```text
Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
```

**Example 2:**

```text
Input: n = 25
Output: 1389537
```

**Constraints:**

* `0 <= n <= 37`
* The answer is guaranteed to fit within a 32-bit integer, ie. `answer <= 2^31 - 1`.

## Solution

```cpp
class Solution {
public:
    int tribonacci(int n) {
        if(n == 0)
            return n;
        if(n == 1 || n == 2)
            return 1;
        
        unsigned int first = 0, second = 1, third = 1;
        unsigned int num = 2;
        while(num < n)
        {
            unsigned int temp = first + second + third;
            first = second;
            second = third;
            third = temp;
            num++;
        }
        return third;
    }
};
```

