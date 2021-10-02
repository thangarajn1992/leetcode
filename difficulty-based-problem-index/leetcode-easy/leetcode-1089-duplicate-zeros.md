# Leetcode 1089 Duplicate Zeros

## Problem Statement

[https://leetcode.com/problems/duplicate-zeros/](https://leetcode.com/problems/duplicate-zeros/)

Given a fixed-length integer array `arr`, duplicate each occurrence of zero, shifting the remaining elements to the right.

**Note** that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.

**Example 1:**

```text
Input: arr = [1,0,2,3,0,4,5,0]
Output: [1,0,0,2,3,0,0,4]
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
```

**Example 2:**

```text
Input: arr = [1,2,3]
Output: [1,2,3]
Explanation: After calling your function, the input array is modified to: [1,2,3]
```

**Constraints:**

* `1 <= arr.length <= 10^4`
* `0 <= arr[i] <= 9`

## Solution

```cpp
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int size = arr.size();
        int possibleDups = 0;
        for(int index = 0; index + possibleDups < size; index++)
        {
            if(arr[index] == 0)
            {
                // Edge case: This zero can't be duplicated. We have no more space,
                // as left is pointing to the last element which could be included  
                if(index + possibleDups == size-1)
                {
                    arr[size - 1] = 0;
                    size--;
                    break;
                }
                possibleDups++;
            }
        }
        
        int last = size - possibleDups - 1;
  
        for(int index = last; index >= 0; index--)
        {
            if(arr[index] == 0)
            {
                arr[index + possibleDups] = 0;
                possibleDups--;
                arr[index + possibleDups] = 0;
            }
            else
            {
                arr[index + possibleDups] = arr[index];
            }
        }
    }
};
```

