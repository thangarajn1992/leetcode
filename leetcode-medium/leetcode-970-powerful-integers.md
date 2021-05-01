# Leetcode 970 Powerful Integers

## Problem Statement

[https://leetcode.com/problems/powerful-integers/](https://leetcode.com/problems/powerful-integers/)

Given three integers `x`, `y`, and `bound`, return _a list of all the **powerful integers** that have a value less than or equal to_ `bound`.

An integer is **powerful** if it can be represented as `xi + yj` for some integers `i >= 0` and `j >= 0`.

You may return the answer in **any order**. In your answer, each value should occur **at most once**.

**Example 1:**

```text
Input: x = 2, y = 3, bound = 10
Output: [2,3,4,5,7,9,10]
Explanation:
2 = 20 + 30
3 = 21 + 30
4 = 20 + 31
5 = 21 + 31
7 = 22 + 31
9 = 23 + 30
10 = 20 + 32
```

**Example 2:**

```text
Input: x = 3, y = 5, bound = 15
Output: [2,4,6,8,10,14]
```

**Constraints:**

* `1 <= x, y <= 100`
* `0 <= bound <= 10^6`

## Solution

```cpp
class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> result;
        if(bound < 2)
            return result;
        int max_x = (x > 1) ? floor(log10(bound)/log10(x)): 0;
        int max_y = (y > 1) ? floor(log10(bound)/log10(y)): 0;
        int sum = 0;
        for(int i = 0; i <= max_x; i++)
            for(int j = 0; j <= max_y; j++)
            {
                sum = pow(x,i) + pow(y,j);
                if(sum > bound)
                    break;
                else if(find(result.begin(), result.end(), sum) == result.end())
                    result.push_back(sum);            
            }                    
        return result;
    }
};
```

