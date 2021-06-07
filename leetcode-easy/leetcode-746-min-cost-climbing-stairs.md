# Leetcode 746 Min Cost Climbing Stairs

## Problem Statement

[https://leetcode.com/problems/min-cost-climbing-stairs/](https://leetcode.com/problems/min-cost-climbing-stairs/)

You are given an integer array `cost` where `cost[i]` is the cost of `ith` step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index `0`, or the step with index `1`.

Return _the minimum cost to reach the top of the floor_.

**Example 1:**

```text
Input: cost = [10,15,20]
Output: 15
Explanation: 
Cheapest is: start on cost[1], pay that cost, and go to the top.
```

**Example 2:**

```text
Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: 
Cheapest is: start on cost[0], and only step on 1s, skipping cost[3].
```

**Constraints:**

* `2 <= cost.length <= 1000`
* `0 <= cost[i] <= 999`

## Solution

```cpp
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int dp[cost.size()+1];
        dp[0] = dp[1] = 0;
        for(int i=2; i<=cost.size(); ++i)
            dp[i] = min(dp[i-2]+cost[i-2], dp[i-1]+cost[i-1]);
        return dp[cost.size()];
    }
};
```

