# Leetcode 374 Guess Number Higher or Lower

## Problem Statement

[https://leetcode.com/problems/guess-number-higher-or-lower/](https://leetcode.com/problems/guess-number-higher-or-lower/)

We are playing the Guess Game. The game is as follows:

I pick a number from `1` to `n`. You have to guess which number I picked.

Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

You call a pre-defined API `int guess(int num)`, which returns 3 possible results:

* `-1`: The number I picked is lower than your guess \(i.e. `pick < num`\).
* `1`: The number I picked is higher than your guess \(i.e. `pick > num`\).
* `0`: The number I picked is equal to your guess \(i.e. `pick == num`\).

Return _the number that I picked_.

**Example 1:**

```text
Input: n = 10, pick = 6
Output: 6
```

**Example 2:**

```text
Input: n = 1, pick = 1
Output: 1
```

**Example 3:**

```text
Input: n = 2, pick = 1
Output: 1
```

**Example 4:**

```text
Input: n = 2, pick = 2
Output: 2
```

**Constraints:**

* `1 <= n <= 2^31 - 1`
* `1 <= pick <= n`

## Solution

### Binary Search Approach

```cpp
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            int guessResult = guess(mid);
            if(guessResult == 0)
                return mid;
            if(guessResult < 0)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
};
```

