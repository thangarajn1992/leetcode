# Leetcode 1887 Reduction Operations to Make the Array Elements Equal

## Problem Statement

[https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/](https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/)

Given an integer array `nums`, your goal is to make all elements in `nums` equal. To complete one operation, follow these steps:

1. Find the **largest** value in `nums`. Let its index be `i` \(**0-indexed**\) and its value be `largest`. If there are multiple elements with the largest value, pick the smallest `i`.
2. Find the **next largest** value in `nums` **strictly smaller** than `largest`. Let its value be `nextLargest`.
3. Reduce `nums[i]` to `nextLargest`.

Return _the number of operations to make all elements in_ `nums` _equal_.

**Example 1:**

```text
Input: nums = [5,1,3]
Output: 3
Explanation: 
It takes 3 operations to make all elements in nums equal:
1. largest = 5 at index 0. nextLargest = 3. Reduce nums[0] to 3. nums = [3,1,3].
2. largest = 3 at index 0. nextLargest = 1. Reduce nums[0] to 1. nums = [1,1,3].
3. largest = 3 at index 2. nextLargest = 1. Reduce nums[2] to 1. nums = [1,1,1].
```

**Example 2:**

```text
Input: nums = [1,1,1]
Output: 0
Explanation: All elements in nums are already equal.
```

**Example 3:**

```text
Input: nums = [1,1,2,2,3]
Output: 4
Explanation: 
It takes 4 operations to make all elements in nums equal:
1. largest = 3 at index 4. nextLargest = 2. Reduce nums[4] to 2. nums = [1,1,2,2,2].
2. largest = 2 at index 2. nextLargest = 1. Reduce nums[2] to 1. nums = [1,1,1,2,2].
3. largest = 2 at index 3. nextLargest = 1. Reduce nums[3] to 1. nums = [1,1,1,1,2].
4. largest = 2 at index 4. nextLargest = 1. Reduce nums[4] to 1. nums = [1,1,1,1,1].
```

**Constraints:**

* `1 <= nums.length <= 5 * 10^4`
* `1 <= nums[i] <= 5 * 10^4`

## Solution

### Map approach O\(n\)

```cpp
class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        /* Map Approach */
        map<int, int> ss;
        for(auto &e: nums)  
            ss[e]++;
        
        if(ss.size() <= 1)    
            return 0;
        
        int result = 0, t = 0;

        for(auto &e: ss){
            result += t * e.second;
            t++;
        }      
        return result;
    }
};
```

### Sort and Count O\(nlogn\)

```cpp
class Solution {
public:
    int reductionOperations(vector<int>& nums) {    
        /* Sorting & Counting */
        int result = 0, count = 0;
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] != nums[i-1])
                count++; 
            result += count;
        }
        return result;
    }
};
```

