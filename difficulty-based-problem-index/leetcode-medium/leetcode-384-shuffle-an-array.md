# Leetcode 384 Shuffle an Array

## Problem Statement

[https://leetcode.com/problems/shuffle-an-array/](https://leetcode.com/problems/shuffle-an-array/)

Given an integer array `nums`, design an algorithm to randomly shuffle the array.

Implement the `Solution` class:

* `Solution(int[] nums)` Initializes the object with the integer array nums.
* `int[] reset()` Resets the array to its original configuration and returns it.
* `int[] shuffle()` Returns a random shuffling of the array.

**Example 1:**

```text
Input
["Solution", "shuffle", "reset", "shuffle"]
[[[1, 2, 3]], [], [], []]
Output
[null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]

Explanation
Solution solution = new Solution([1, 2, 3]);

// Shuffle the array [1,2,3] and return its result. 
// Any permutation of [1,2,3] must be equally likely to be returned. 
// Example: return [3, 1, 2]
solution.shuffle();  
  
// Resets the array back to its original configuration [1,2,3]. Return [1, 2, 3]
solution.reset();  

// Returns the random shuffling of array [1,2,3]. Example: return [1, 3, 2]        
solution.shuffle();    

```

**Constraints:**

* `1 <= nums.length <= 200`
* `-10^6 <= nums[i] <= 10^6`
* All the elements of `nums` are **unique**.
* At most `5 * 10^4` calls will be made to `reset` and `shuffle`.

## Solution

```cpp
class Solution {
public:
    vector<int> vec;
    Solution(vector<int>& nums) {
        vec = nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return vec;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> temp = vec;
        for(int i = 0; i < temp.size(); i++)
        {
            int j = rand() % temp.size();
            swap(temp[i], temp[j]);
        }
        return temp;
    }
};
```

