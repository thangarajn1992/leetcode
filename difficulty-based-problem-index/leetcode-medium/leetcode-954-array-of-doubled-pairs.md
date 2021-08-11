# Leetcode 954 Array of Doubled Pairs

## Problem Statement

[https://leetcode.com/problems/array-of-doubled-pairs/](https://leetcode.com/problems/array-of-doubled-pairs/)

Given an array of integers `arr` of even length, return `true` if and only if it is possible to reorder it such that `arr[2 * i + 1] = 2 * arr[2 * i]` for every `0 <= i < len(arr) / 2`.

**Example 1:**

```text
Input: arr = [3,1,3,6]
Output: false
```

**Example 2:**

```text
Input: arr = [2,1,2,6]
Output: false
```

**Example 3:**

```text
Input: arr = [4,-2,2,-4]
Output: true
Explanation: 
We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4] or [2,4,-2,-4].
```

**Example 4:**

```text
Input: arr = [1,2,4,16,8,4]
Output: false
```

**Constraints:**

* `0 <= arr.length <= 3 * 10^4`
* `arr.length` is even.
* `-10^5 <= arr[i] <= 10^5`

## Solution

```cpp
class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int,int> m;
        for(auto a : arr) 
            m[a]++;
            
        vector<int> keys;
        for(auto it = m.begin(); it != m.end(); it++) {
            keys.push_back(it->first);
        }
        
        sort(keys.begin(), keys.end(), [](int a, int b) {
            return abs(a) < abs(b);
        });
        
        for(int i = 0; i < keys.size(); i++) {
            int key = keys[i], target = 2 * key;
            if (m[target] < m[key]) 
                return false;
            m[target] -= m[key];
        }
        return true; 
    }
};
```

#### Testcases

```cpp
Inputs
[3,1,3,6]
[1,2,4,16,8,4]
[1,2,4,8,4,8]
[4,-2,2,-4]
[0,0]
[-5,-2]
[-6,-3]

Output:
false
false
true
true
true
false
true
```

