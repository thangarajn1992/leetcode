# Leetcode 1354 Construct Target Array With Multiple Sums

## Problem Statement

[https://leetcode.com/problems/construct-target-array-with-multiple-sums/](https://leetcode.com/problems/construct-target-array-with-multiple-sums/)

Given an array of integers `target`. From a starting array, `A` consisting of all 1's, you may perform the following procedure :

* let `x` be the sum of all elements currently in your array.
* choose index `i`, such that `0 <= i < target.size` and set the value of `A` at index `i` to `x`.
* You may repeat this procedure as many times as needed.

Return True if it is possible to construct the `target` array from `A` otherwise return False.

**Example 1:**

```text
Input: target = [9,3,5]
Output: true
Explanation: Start with [1, 1, 1] 
[1, 1, 1], sum = 3 choose index 1
[1, 3, 1], sum = 5 choose index 2
[1, 3, 5], sum = 9 choose index 0
[9, 3, 5] Done
```

**Example 2:**

```text
Input: target = [1,1,1,2]
Output: false
Explanation: Impossible to create target array from [1,1,1,1].
```

**Example 3:**

```text
Input: target = [8,5]
Output: true
```

**Constraints:**

* `N == target.length`
* `1 <= target.length <= 5 * 10^4`
* `1 <= target[i] <= 10^9`

## Solution

```cpp
class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int> q;
        long sum = 0;
        
        for (auto num : target) {
            q.push(num);
            sum += num;
        }
        
        while (!q.empty()) {
            int curr_max = q.top();
            q.pop();
            if (curr_max == 1) return true;

            long rest = sum - curr_max;
            
            if (rest == 0) return false;
            if (rest == 1) return true;
            if(rest >= curr_max) return false;

            rest = curr_max % rest;
            if (rest == 0) return false;
            
            sum -= (curr_max - rest);
            q.push(rest);

        }
        return true;
    }
};
```

