# Leetcode 1862 Sum of Floored Pairs

## Problem Statement

[https://leetcode.com/problems/sum-of-floored-pairs/](https://leetcode.com/problems/sum-of-floored-pairs/)

Given an integer array `nums`, return the sum of `floor(nums[i] / nums[j])` for all pairs of indices `0 <= i, j < nums.length` in the array. Since the answer may be too large, return it **modulo** `109 + 7`.

The `floor()` function returns the integer part of the division.

**Example 1:**

```text
Input: nums = [2,5,9]
Output: 10
Explanation:
floor(2 / 5) = floor(2 / 9) = floor(5 / 9) = 0
floor(2 / 2) = floor(5 / 5) = floor(9 / 9) = 1
floor(5 / 2) = 2
floor(9 / 2) = 4
floor(9 / 5) = 1
We calculate the floor of the division for every pair of indices in the array then 
sum them up.
```

**Example 2:**

```text
Input: nums = [7,7,7,7,7,7,7]
Output: 49
```

**Constraints:**

* `1 <= nums.length <= 10^5`
* `1 <= nums[i] <= 10^5`

## Explanation

We can't iterate sum up for all the possible pairs since the given constraints would lead to TLE.

We need to observe that the result of _`floor(nums[i] / nums[j])`_, will be -

* **`0`** if `nums[i] < nums[j]`
* **`1`** if `nums[j] <= nums[i] < (2 * nums[j])`
* **`2`** if `2 * nums[j] <= nums[i] < (3 * nums[j])`
* and so on...

We can use this to build a **frequency array** and then **calculate the prefix sum of it**.

After this, for every _`num`_ in _`nums`_, we will add the answer into _`sum`_ as per the above observation.

* All the numbers in the range`[0, num - 1]`will contribute **0** to the sum each. The **frequency of numbers in this range** will be given by _`freq[num - 1] - freq[0]`_.
* All the numbers in the range`[num, 2*num - 1]`will contribute **1** to the sum each. **Frequency:** _`freq[num] - freq[2num - 1]`_.
* Numbers in`[2*num, 3*num - 1]`will contribute **3** each. **Frequency:** _`freq[2num] - freq[3num - 1]`_.
* And so on till our range covers the maximum element of the _`nums`_ array...

## Solution

```cpp
class Solution {
public:
    const int MAXN = 1e5 + 1, MOD = 1e9 + 7;
    int sumOfFlooredPairs(vector<int>& nums) {
        vector<long> freq(2*MAXN+1);        
	    long mx = 0, sum = 0;
        
        // counting frequency of each element in nums
	    for(auto num : nums) 
            ++freq[num], mx = max((int)mx, num);  
        
        // building prefix sum array of freq. 
        //Now freq[i] will hold the frequency of numbers less than or equal to i
	    for(int i = 1; i <= 2*MAXN; ++i) 
            freq[i] += freq[i - 1];   

	    // Each num will be assumed in the denominator as floor(nums[i] / num) and 
	    // using freq array, we can calculate the number of terms contributing 1, 2, 3...             to the sum each.
        map<int,int> calc;
	    for(auto num : nums) { 
            if(calc[num])
            {
                sum = (sum + calc[num]) % MOD;
                continue;
            }
		    long l = num, r = 2 * num, divResult = 1;
            int temp = 0;
		    while(l <= mx) { 
			    temp = (temp + divResult * (freq[r - 1] - freq[l - 1])) % MOD;
			    l += num, r += num;
			    ++divResult;
		    }
            calc[num] = temp;
            sum  = ( sum + temp) % MOD;
	    }
	    return sum;
    }
};
```

