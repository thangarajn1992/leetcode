# Leetcode 1866 Number of Ways to Rearrange Sticks With K Sticks Visible

## Problem Statement

[https://leetcode.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible/](https://leetcode.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible/)

There are `n` uniquely-sized sticks whose lengths are integers from `1` to `n`. You want to arrange the sticks such that **exactly** `k` sticks are **visible** from the left. A stick is **visible** from the left if there are no **longer** sticks to the **left** of it.

* For example, if the sticks are arranged `[1,3,2,5,4]`, then the sticks with lengths `1`, `3`, and `5` are visible from the left.

Given `n` and `k`, return _the **number** of such arrangements_. Since the answer may be large, return it **modulo** `109 + 7`.

**Example 1:**

```text
Input: n = 3, k = 2
Output: 3
Explanation: [1,3,2], [2,3,1], and [2,1,3] are the only arrangements such that exactly 2 sticks are visible.
The visible sticks are underlined.
```

**Example 2:**

```text
Input: n = 5, k = 5
Output: 1
Explanation: [1,2,3,4,5] is the only arrangement such that all 5 sticks are visible.
The visible sticks are underlined.
```

**Example 3:**

```text
Input: n = 20, k = 11
Output: 647427950
Explanation: There are 647427950 (mod 109 + 7) ways to rearrange the sticks such that exactly 11 sticks are visible.
```

**Constraints:**

* `1 <= n <= 1000`
* `1 <= k <= n`

## Explanation

### Top-Down DP Approach:

Let's say n = 5, k = 3.

Starting from the leftmost position, for the first position, we have five options to choose from. If we choose 3 at the first position, then we are left with the set`{1, 2, 4, 5}`and the sticks of sizes 1 and 2 can never be seen from the left side. So we must maintain the order that 4 comes before 5 \(because we need 3 sticks to be visible\) and the rest of the order can be anything \(for example`[1, 2, 4, 5], [2, 4, 5, 1],`and many other possibilities\). So for any state \(n, k\), we must also have information about what the tallest stick on the left is, and how many of the remaining sticks are smaller than that stick. Without it, we cannot do anything. And **keeping track of all this information seems to be a lot and it also increases the complexity beyond the given constraints.** I mentioned this because this was my first thought too. And after realizing that this is too complex, I started thinking in a different direction.

Another way to think about this problem is to assign a stick to the rightmost position first. After selecting a stick for the rightmost position, we will be left with`n - 1`sticks of different sizes that will go on its left and there will be no restriction imposed by the stick we selected to be at the rightmost position. We just need to track whether the stick we selected at the rightmost position will be visible from the left side or not. And figuring that out is easy. It will be visible from the left side if it was the tallest of all the sticks we had. And it will not be visible from the left if it wasn't the tallest stick. So the two possibilities for the rightmost stick selection at any point where we have n sticks and k of them need to be visible from the left:

1. We select the tallest of the n sticks. There's only one such stick and this stick will finally be visible from the left. And so we are left with the sub-problem \(n - 1, k - 1\).
2. We select a stick that's not the tallest one. We can do this by selecting any of the n - 1 sticks that are not the tallest one. So there are n - 1 sub-problems and each of them is \(n - 1, k\). This stick we selected will not be visible from the left, so we still gotta select k sticks from the remaining pile that will be visible, that's why the sub-problem has k, and not k - 1.

## Solution

```cpp
class Solution {
public:
    vector<vector<long long>> dp;
    long long mod = 1e9 + 7;
    int nums(long long n, long long k)
    {
        if(k == 0 || k > n) 
            return 0;
        if(n <= 2) 
            return 1;
        if(dp[n][k] != -1)
            return dp[n][k];
        
        long long ans = 0;
        
        // If we select the largest stick to the right
        ans = (ans + nums(n-1,k-1)) % mod;
        
        // If we select any one of the non-largest stick to the right
        ans = (ans + ((n-1) * nums(n-1,k))) % mod;
        
        dp[n][k] = ans;
        return dp[n][k];
    }
    int rearrangeSticks(int n, int k) {
        dp = vector<vector<long long>>( n+1, vector<long long>(k+1, -1));
        return nums(n,k);
    }
};
```

