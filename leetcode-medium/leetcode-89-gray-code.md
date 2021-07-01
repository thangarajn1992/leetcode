# Leetcode 89 Gray Code

## Problem Statement

[https://leetcode.com/problems/gray-code/](https://leetcode.com/problems/gray-code/)

An **n-bit gray code sequence** is a sequence of `2^n` integers where:

* Every integer is in the **inclusive** range `[0, 2^n - 1]`,
* The first integer is `0`,
* An integer appears **no more than once** in the sequence,
* The binary representation of every pair of **adjacent** integers differs by **exactly one bit**, and
* The binary representation of the **first** and **last** integers differs by **exactly one bit**.

Given an integer `n`, return _any valid **n-bit gray code sequence**_.

**Example 1:**

```text
Input: n = 2
Output: [0,1,3,2]
Explanation:
The binary representation of [0,1,3,2] is [00,01,11,10].
- 00 and 01 differ by one bit
- 01 and 11 differ by one bit
- 11 and 10 differ by one bit
- 10 and 00 differ by one bit
[0,2,3,1] is also a valid gray code sequence, whose binary representation is [00,10,11,01].
- 00 and 10 differ by one bit
- 10 and 11 differ by one bit
- 11 and 01 differ by one bit
- 01 and 00 differ by one bit
```

**Example 2:**

```text
Input: n = 1
Output: [0,1]
```

**Constraints:**

* `1 <= n <= 16`

## Solution

{% tabs %}
{% tab title="Iterative" %}
```cpp
class Solution {
public: 
    /* Iterative Approach */
    vector<int> grayCode(int n) {
        vector<int> result = {0,1};
        for(int i = 2; i <= n; i++)
        {
            int size = result.size();
            for(int j = size-1; j >= 0 ; j--)
                result.push_back(result[j] | (1 << (i-1)));
        }
        return result;
    }
};
```
{% endtab %}

{% tab title="Recursion" %}
```cpp
class Solution {
public: 
    /* Recursive */
    vector<int> grayCode(int n) {
        if(n == 1){  // base-case
            vector<int> tmp = {0,1};
            return tmp;
        }
        
        vector<int> nums = grayCode(n-1);
        for(int i = nums.size() - 1; i >= 0; i--)
            nums.push_back(nums[i] | (1 << (n-1)));
        
        return nums;
    }
};



```
{% endtab %}
{% endtabs %}

