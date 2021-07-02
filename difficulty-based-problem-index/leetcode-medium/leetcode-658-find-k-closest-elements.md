# Leetcode 658 Find K Closest Elements

## Problem Statement

[https://leetcode.com/problems/find-k-closest-elements/](https://leetcode.com/problems/find-k-closest-elements/)

Given a **sorted** integer array `arr`, two integers `k` and `x`, return the `k` closest integers to `x` in the array. The result should also be sorted in ascending order.

An integer `a` is closer to `x` than an integer `b` if:

* `|a - x| < |b - x|`, or
* `|a - x| == |b - x|` and `a < b`

**Example 1:**

```text
Input: arr = [1,2,3,4,5], k = 4, x = 3
Output: [1,2,3,4]
```

**Example 2:**

```text
Input: arr = [1,2,3,4,5], k = 4, x = -1
Output: [1,2,3,4]
```

**Constraints:**

* `1 <= k <= arr.length`
* `1 <= arr.length <= 10^4`
* `arr` is sorted in **ascending** order.
* `-10^4 <= arr[i], x <= 10^4`

## Solution

```cpp
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        // start element of element can be from index 0 to size - k
        int left = 0, right = arr.size() - k; 
        
        //Find the index that will be the first element in the result
        while (left < right)
        {
            int mid = left + (right - left)/2;
            if (x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }  
        return vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};
```

