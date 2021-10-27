# Leetcode 1863 Sum of All Subset XOR Totals

## Problem Statement

[https://leetcode.com/problems/sum-of-all-subset-xor-totals/](https://leetcode.com/problems/sum-of-all-subset-xor-totals/)

The **XOR total** of an array is defined as the bitwise `XOR` of **all its elements**, or `0` if the array is **empty**.

* For example, the **XOR total** of the array `[2,5,6]` is `2 XOR 5 XOR 6 = 1`.

Given an array `nums`, return _the **sum** of all **XOR totals** for every **subset** of_ `nums`.&#x20;

**Note:** Subsets with the **same** elements should be counted **multiple** times.

An array `a` is a **subset** of an array `b` if `a` can be obtained from `b` by deleting some (possibly zero) elements of `b`.

**Example 1:**

```
Input: nums = [1,3]
Output: 6
Explanation: 
The 4 subsets of [1,3] are:
- The empty subset has an XOR total of 0.
- [1] has an XOR total of 1.
- [3] has an XOR total of 3.
- [1,3] has an XOR total of 1 XOR 3 = 2.
0 + 1 + 3 + 2 = 6
```

**Example 2:**

```
Input: nums = [5,1,6]
Output: 28
Explanation: 
The 8 subsets of [5,1,6] are:
- The empty subset has an XOR total of 0.
- [5] has an XOR total of 5.
- [1] has an XOR total of 1.
- [6] has an XOR total of 6.
- [5,1] has an XOR total of 5 XOR 1 = 4.
- [5,6] has an XOR total of 5 XOR 6 = 3.
- [1,6] has an XOR total of 1 XOR 6 = 7.
- [5,1,6] has an XOR total of 5 XOR 1 XOR 6 = 2.
0 + 5 + 1 + 6 + 4 + 3 + 7 + 2 = 28
```

**Example 3:**

```
Input: nums = [3,4,5,6,7,8]
Output: 480
Explanation: 
The sum of all XOR totals for every subset is 480.
```

**Constraints:**

* `1 <= nums.length <= 12`
* `1 <= nums[i] <= 20`

## Explanation

The idea is

```
    1 = 001
    5 = 101
    6 = 110
1 ^ 5 = 100
1 ^ 6 = 111
5 ^ 6 = 011
1^5^6 = 010
```

Once we observe all these binary numbers of the XORs, we can observe that set bit occurs at all the position of i (0 <= i< n) will **exactly contribute to half of pow(2,n)**.

**Note:** `2^n` represents `pow(2,n)`, using the same notation for XOR in the above example but not in the following cases.

**Why exactly half of `2^n`??**

* Consider the size of `nums` array is `n` and `m` elements in `nums` have `i` th bit set.
* Now, to have a subset with `i`th bit set in its `xor`, we need it to have odd number of elements with `i`th bit set or else `xor` will become `0`.
* Number of ways of choosing elements with `i`th bit not set = `2^(n-m)`.
* Also, Number of ways of choosing elements with `i`th bit set = `mC1 + mC3 + mC5 …. = 2^(m-1)`
* So that we get total number of ways = `2^(n-1)` which is exactly half of `2^n`.

Now, we have two conditions:

* If there is any value of `nums` that has set `i`th bit set, then exactly half of `2^n` subsets will be of the form, so they will contribute to `2^(n-1+i)` to the final sum.
* If there is no value of `nums` that `i`th bit set, then we can say that there will be no term in all subsets that have a `i`th bit set.\
  &#x20;\-> Now the question is to check which position of element of the `nums` will be set or not. But instead of iterating for all elements , we can use a trick that is simply take the `OR` of all such values and multiply with `2^(n-1)`

```
Take a OR of all  elements, we get 
= 1 | 5 | 6
= 001 | 101 | 110
= 111
Now to find final summation, 
= 1*2^(n-1+2) + 1*2^(n-1+1) + 1*2^(n-1+0)
= 2^(n-1) * (1*2^2 + 1*2^1 + 1*2^0 )
= 2^(n-1) * 7
so final result will be putting n=3, 
= 28
```

## Solution

```cpp
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int bits = 0;
 
        // Finding bitwise OR of all elements
        for (int i = 0; i < nums.size(); ++i)
            bits |= nums[i];
 
        int ans = bits * pow(2,nums.size()-1);
 
        return ans;
    }
};
```
