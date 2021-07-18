# Leetcode 927 Three Equal Parts

## Problem Statement

[https://leetcode.com/problems/three-equal-parts/](https://leetcode.com/problems/three-equal-parts/)

You are given an array `arr` which consists of only zeros and ones, divide the array into **three non-empty parts** such that all of these parts represent the same binary value.

If it is possible, return any `[i, j]` with `i + 1 < j`, such that:

* `arr[0], arr[1], ..., arr[i]` is the first part,
* `arr[i + 1], arr[i + 2], ..., arr[j - 1]` is the second part, and
* `arr[j], arr[j + 1], ..., arr[arr.length - 1]` is the third part.
* All three parts have equal binary values.

If it is not possible, return `[-1, -1]`.

Note that the entire part is used when considering what binary value it represents. For example, `[1,1,0]` represents `6` in decimal, not `3`. Also, leading zeros **are allowed**, so `[0,1,1]` and `[1,1]` represent the same value.

**Example 1:**

```text
Input: arr = [1,0,1,0,1]
Output: [0,3]
```

**Example 2:**

```text
Input: arr = [1,1,0,1,1]
Output: [-1,-1]
```

**Example 3:**

```text
Input: arr = [1,1,0,0,1]
Output: [0,2]
```

**Constraints:**

* `3 <= arr.length <= 3 * 10^4`
* `arr[i]` is `0` or `1`

## Solution

```cpp
class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        vector<int> ones;
        for (int i = 0; i < arr.size(); ++i) 
            if (arr[i] == 1) 
                ones.push_back(i);
        
        if (ones.size() == 0) 
            return vector{0, 2};
        
        if (ones.size() % 3 != 0) 
            return vector{-1, -1};
        
        int len = arr.size() - ones[(ones.size() / 3) * 2];
        
        int part1_firstone = ones[0];
        int part2_firstone = ones[ones.size() / 3];
        int part3_firstone = ones[ones.size() / 3 * 2];
        
        for (int i = 0; i < len; ++i)
            if (arr[part1_firstone + i] != arr[part2_firstone + i] ||
                arr[part1_firstone + i] != arr[part3_firstone + i]) 
                return vector{-1, -1};
        return vector{part1_firstone + len - 1, part2_firstone + len};
    }
};
```

