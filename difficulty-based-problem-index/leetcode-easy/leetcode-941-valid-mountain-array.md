# Leetcode 941 Valid Mountain Array

## Problem Statement

[https://leetcode.com/problems/valid-mountain-array/](https://leetcode.com/problems/valid-mountain-array/)

Given an array of integers `arr`, return _`true` if and only if it is a valid mountain array_.

Recall that arr is a mountain array if and only if:

* `arr.length >= 3`
* There exists some `i` with `0 < i < arr.length - 1` such that:
  * `arr[0] < arr[1] < ... < arr[i - 1] < arr[i]`
  * `arr[i] > arr[i + 1] > ... > arr[arr.length - 1]`

![](https://assets.leetcode.com/uploads/2019/10/20/hint_valid_mountain_array.png)

**Example 1:**

```text
Input: arr = [2,1]
Output: false
```

**Example 2:**

```text
Input: arr = [3,5,5]
Output: false
```

**Example 3:**

```text
Input: arr = [0,3,2,1]
Output: true
```

**Constraints:**

* `1 <= arr.length <= 10^4`
* `0 <= arr[i] <= 10^4`

## Solution

```cpp
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int size = arr.size();
        int index = 0;
              
        // keep going up till we reach peak
        while(index < size-1 && arr[index] < arr[index+1])
            index++;
        
        // Peak cannot be first or last element
        if(index == 0 || index == size - 1)
            return false;
        
        // keep going down
        while(index < size-1 && arr[index] > arr[index+1])
            index++;
        
        return index == size-1;
    }
};
```

