# Leetcode 1338 Reduce Array Size to The Half

## Problem Statement

[https://leetcode.com/problems/reduce-array-size-to-the-half/](https://leetcode.com/problems/reduce-array-size-to-the-half/)

Given an array `arr`.  You can choose a set of integers and remove all the occurrences of these integers in the array.

Return _the minimum size of the set_ so that **at least** half of the integers of the array are removed.

**Example 1:**

```text
Input: arr = [3,3,3,3,5,5,5,2,2,7]
Output: 2
Explanation: 
Choosing {3,7} will make the new array [5,5,5,2,2] which has size 5 (i.e equal to half of 
the size of the old array).
Possible sets of size 2 are {3,5},{3,2},{5,2}.
Choosing set {2,7} is not possible as it will make the new array [3,3,3,3,5,5,5] which 
has size greater than half of the size of the old array.
```

**Example 2:**

```text
Input: arr = [7,7,7,7,7,7]
Output: 1
Explanation: 
The only possible set you can choose is {7}. This will make the new array empty.
```

**Example 3:**

```text
Input: arr = [1,9]
Output: 1
```

**Example 4:**

```text
Input: arr = [1000,1000,3,7]
Output: 1
```

**Example 5:**

```text
Input: arr = [1,2,3,4,5,6,7,8,9,10]
Output: 5
```

**Constraints:**

* `1 <= arr.length <= 10^5`
* `arr.length` is even.
* `1 <= arr[i] <= 10^5`

## Solution

### My Approach

```cpp
class Solution {
public:
    int minSetSize(vector<int>& arr) {
        vector<int> freq(100001);
        int size = arr.size();
        
        for(int num = 0; num < size; num++)
            freq[arr[num]]++;
        
        sort(freq.begin(), freq.end(), greater<>());
        
        int result = 0, count = 0;
        for(int num = 0; num < freq.size(); num++)
        {
            result++;
            count += freq[num];
            if(count >= size/2)
                break;
        }
        return result;
    }
};
```

