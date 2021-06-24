# Leetcode 1860 Incremental Memory Leak

## Problem Statement

[https://leetcode.com/problems/incremental-memory-leak/](https://leetcode.com/problems/incremental-memory-leak/)

You are given two integers `memory1` and `memory2` representing the available memory in bits on two memory sticks. There is currently a faulty program running that consumes an increasing amount of memory every second.

At the `ith` second \(starting from 1\), `i` bits of memory are allocated to the stick with **more available memory** \(or from the first memory stick if both have the same available memory\). If neither stick has at least `i` bits of available memory, the program **crashes**.

Return _an array containing_ `[crashTime, memory1crash, memory2crash]`_, where_ `crashTime` _is the time \(in seconds\) when the program crashed and_ `memory1crash` _and_ `memory2crash` _are the available bits of memory in the first and second sticks respectively_.

**Example 1:**

```text
Input: memory1 = 2, memory2 = 2
Output: [3,1,0]
Explanation: 
The memory is allocated as follows:
- At the 1st second, 1 bit of memory is allocated to stick 1. 
    The first stick now has 1 bit of available memory.
- At the 2nd second, 2 bits of memory are allocated to stick 2. 
    The second stick now has 0 bits of available memory.
- At the 3rd second, the program crashes. T
    he sticks have 1 and 0 bits available respectively.
```

**Example 2:**

```text
Input: memory1 = 8, memory2 = 11
Output: [6,0,4]
Explanation: 
The memory is allocated as follows:
- At the 1st second, 1 bit of memory is allocated to stick 2. 
    The second stick now has 10 bit of available memory.
- At the 2nd second, 2 bits of memory are allocated to stick 2. 
    The second stick now has 8 bits of available memory.
- At the 3rd second, 3 bits of memory are allocated to stick 1. 
    The first stick now has 5 bits of available memory.
- At the 4th second, 4 bits of memory are allocated to stick 2. 
    The second stick now has 4 bits of available memory.
- At the 5th second, 5 bits of memory are allocated to stick 1. 
    The first stick now has 0 bits of available memory.
- At the 6th second, the program crashes. 
    The sticks have 0 and 4 bits available respectively.
```

**Constraints:**

* `0 <= memory1, memory2 <= 2^31 - 1`

## Solution

```cpp
class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int i = 1;
        while(memory1 >= i || memory2 >= i)
        {
            if(memory2 > memory1)
                memory2 -= i;
            else if(memory1 >= i)
                memory1 -= i;
            i++;
        }
        return {i, memory1, memory2};
    }
};
```

