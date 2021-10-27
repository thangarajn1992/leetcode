# Leetcode 1465 Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts

## Problem Statement

[https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/](https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/)

Given a rectangular cake with height `h` and width `w`, and two arrays of integers `horizontalCuts` and `verticalCuts` where `horizontalCuts[i]` is the distance from the top of the rectangular cake to the `ith` horizontal cut and similarly, `verticalCuts[j]` is the distance from the left of the rectangular cake to the `jth` vertical cut.

_Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays `horizontalCuts` and `verticalCuts`. _Since the answer can be a huge number, return this modulo 10^9 + 7.

**Example 1:**

![](https://assets.leetcode.com/uploads/2020/05/14/leetcode\_max\_area\_2.png)

```
Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
Output: 4 
Explanation: 
The figure above represents the given rectangular cake. Red lines are the horizontal 
and vertical cuts. After you cut the cake, the green piece of cake has the maximum area.
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2020/05/14/leetcode\_max\_area\_3.png)

```
Input: h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
Output: 6
Explanation: 
The figure above represents the given rectangular cake. Red lines are the horizontal 
and vertical cuts. After you cut the cake, the green and yellow pieces of cake have 
the maximum area.
```

**Example 3:**

```
Input: h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
Output: 9
```

**Constraints:**

* `2 <= h, w <= 10^9`
* `1 <= horizontalCuts.length < min(h, 10^5)`
* `1 <= verticalCuts.length < min(w, 10^5)`
* `1 <= horizontalCuts[i] < h`
* `1 <= verticalCuts[i] < w`
* It is guaranteed that all elements in `horizontalCuts` are distinct.
* It is guaranteed that all elements in `verticalCuts` are distinct.

## Solution

```cpp
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());

        int row_max = max(horizontalCuts[0], h - horizontalCuts.back());
        int col_max = max(verticalCuts[0], w - verticalCuts.back());
        
        for(int row = 1; row < horizontalCuts.size(); row++)
            row_max = max(row_max, horizontalCuts[row] - horizontalCuts[row-1]);
        
        for(int col = 1; col < verticalCuts.size(); col++)
            col_max = max(col_max, verticalCuts[col] - verticalCuts[col-1]);
        
        return long(row_max) * long(col_max) % 1000000007;
    }
};
```
