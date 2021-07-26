# Leetcode 600 Non-negative Integers without Consecutive Ones

## Problem Statement

[https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/](https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/)

Given a positive integer `n`, return the number of the integers in the range `[0, n]` whose binary representations **do not** contain consecutive ones.

**Example 1:**

```text
Input: n = 5
Output: 5
Explanation:
Here are the non-negative integers <= 5 with their corresponding binary representations:
0 : 0
1 : 1
2 : 10
3 : 11
4 : 100
5 : 101
Among them, only integer 3 disobeys the rule (two consecutive ones) and 
the other 5 satisfy the rule. 
```

**Example 2:**

```text
Input: n = 1
Output: 2
```

**Example 3:**

```text
Input: n = 2
Output: 3
```

**Constraints:**

* `1 <= n <= 10^9`

## Solution

### Approach

we need to find the count of binary numbers withnnn bits such that these numbers don't contain consecutive 1's. In order to do so, we can look at the problem in a recursive fashion. Supposef\[i\]f\[i\]f\[i\] gives the count of such binary numbers withiii bits. In order to determine the value off\[n\]f\[n\]f\[n\], which is the requirement, we can consider the cases shown below:

![Recursive\_Function](https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/Figures/600_Non_Negative_1.png)

From the above figure, we can see that if we know the value of `f[n−1]` and `f[n−2]],` in order to generate the required binary numbers withnnn bits, we can append a `0` to all the binary numbers contained in `f[n−1]` without creating an invalid number. These numbers give a factor of `f[n−1]` to be included in `f[n]`. But, we can't append a `1` to all these numbers, since it could lead to the presence of two consecutive ones in the newly generated numbers. Thus, for the currently generated numbers to end with a `1`, we need to ensure that the second last position is always `0`. Thus, we need to fix a `01` at the end of all the numbers contained in `f[n−2]`. This gives a factor of `f[n−2]` to be included in `f[n]`. Thus, in total, we get `f[n]=f[n−1]+f[n−2]`

1. We start scanning the given number num from its MSB. 
2. For every 1 encountered at the ith bit position\(counting from 0 from LSB\), we add a factor of func\[i\] to the resultant count. 
3. For every 0 encountered, we don't add any factor.
4. We also keep a track of the last bit checked. 
5. If we happen to find two consecutive 1's at any time, we add the factors for the positions of both the 1's and stop the traversal immediately. 
6. If we don't find any two consecutive 1's, we proceed till reaching the LSB and add an extra 1 to account for the given number num as well 

```cpp
class Solution {
public:
    int findIntegers(int n) {
        vector<int> func(32);
        func[0] = 1;
        func[1] = 2;
        for (int i = 2; i < 32; i++)
            func[i] = func[i - 1] + func[i - 2];
        int i = 30, sum = 0, prev_bit = 0;
        while (i >= 0) {
            if ((n & (1 << i)) != 0) { // If bit is 1
                sum += func[i];
                if (prev_bit == 1) {
                    return sum; // consecutive one in given "n"
                }
                prev_bit = 1;
            } else
                prev_bit = 0;
            i--;
        }
        return sum + 1;  // no consecutive one in given "n"    
    }
};
```

