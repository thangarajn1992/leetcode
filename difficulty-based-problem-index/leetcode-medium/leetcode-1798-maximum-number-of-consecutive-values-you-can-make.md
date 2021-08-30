# Leetcode 1798 Maximum Number of Consecutive Values You Can Make

## Problem Statement

[https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/](https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/)\

You are given an integer array `coins` of length `n` which represents the `n` coins that you own. The value of the `ith` coin is `coins[i]`. You can **make** some value `x` if you can choose some of your `n` coins such that their values sum up to `x`.

Return the _maximum number of consecutive integer values that you **can** **make** with your coins **starting** from and **including**_ `0`.

Note that you may have multiple coins of the same value.

**Example 1:**

```text
Input: coins = [1,3]
Output: 2
Explanation: You can make the following values:
- 0: take []
- 1: take [1]
You can make 2 consecutive integer values starting from 0.
```

**Example 2:**

```text
Input: coins = [1,1,1,4]
Output: 8
Explanation: You can make the following values:
- 0: take []
- 1: take [1]
- 2: take [1,1]
- 3: take [1,1,1]
- 4: take [4]
- 5: take [4,1]
- 6: take [4,1,1]
- 7: take [4,1,1,1]
You can make 8 consecutive integer values starting from 0.
```

**Example 3:**

```text
Input: nums = [1,4,10,3,1]
Output: 20
```

**Constraints:**

* `coins.length == n`
* `1 <= n <= 4 * 10^4`
* `1 <= coins[i] <= 4 * 10^4`

## Solution

1. Sort the array in ascending order.
2. Initialize the maximum reachable number to 1. and start traversing the array
3. As long as arr\[i\] &lt;= maximum reachable number, then we can reach maximum reachable number + arr\[i\]. `maximum reachable number += arr[i]`
4. Else, we return the current maximum reachable value.

```cpp
class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        sort(coins.begin(), coins.end());
        int maxConsecutiveValue = 1; // we can always make 0 with empty subset
        for(int coin = 0; coin < coins.size(); coin++)
        {
            if(coins[coin] <= maxConsecutiveValue)
                maxConsecutiveValue += coins[coin];
            else
                break;
        }
        return maxConsecutiveValue;
    }
};
```

