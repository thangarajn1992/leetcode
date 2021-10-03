# Leetcode 1051 Height Checker

## Problem Statement

[https://leetcode.com/problems/height-checker/](https://leetcode.com/problems/height-checker/)

A school is trying to take an annual photo of all the students. The students are asked to stand in a single file line in **non-decreasing order** by height. Let this ordering be represented by the integer array `expected` where `expected[i]` is the expected height of the `ith` student in line.

You are given an integer array `heights` representing the **current order** that the students are standing in. Each `heights[i]` is the height of the `ith` student in line \(**0-indexed**\).

Return _the **number of indices** where_ `heights[i] != expected[i]`.

**Example 1:**

```text
Input: heights = [1,1,4,2,1,3]
Output: 3
Explanation: 
heights:  [1,1,4,2,1,3]
expected: [1,1,1,2,3,4]
Indices 2, 4, and 5 do not match.
```

**Example 2:**

```text
Input: heights = [5,1,2,3,4]
Output: 5
Explanation:
heights:  [5,1,2,3,4]
expected: [1,2,3,4,5]
All indices do not match.
```

**Example 3:**

```text
Input: heights = [1,2,3,4,5]
Output: 0
Explanation:
heights:  [1,2,3,4,5]
expected: [1,2,3,4,5]
All indices match.
```

**Constraints:**

* `1 <= heights.length <= 100`
* `1 <= heights[i] <= 100`

## Solution

### Two Pointer Approach

```cpp
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int size = heights.size();
        
        vector<int> freq(101,0);
        for(int height : heights)
            freq[height]++;
        
        int currentHeight = 0;
        int mismatchCount = 0;

        for(int index = 0; index < size; index++)
        {
            while(freq[currentHeight] == 0)
                currentHeight++;
            
            if(currentHeight != heights[index])
                mismatchCount++;
            
            freq[currentHeight]--;
        }
        return mismatchCount;
    }
};
```

