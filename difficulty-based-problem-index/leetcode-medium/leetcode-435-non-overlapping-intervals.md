# Leetcode 435 Non-Overlapping Intervals

## Problem Statement

Given an array of intervals `intervals` where `intervals[i] = [starti, endi]`, return _the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping_.

**Example 1:**

```
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: 
[1,3] can be removed and the rest of the intervals are non-overlapping.
```

**Example 2:**

```
Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: 
You need to remove two [1,2] to make the rest of the intervals non-overlapping.
```

**Example 3:**

```
Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: 
You don't need to remove any of the intervals since they're already non-overlapping.
```

&#x20;

**Constraints:**

* `1 <= intervals.length <= 10^5`
* `intervals[i].length == 2`
* `-5 * 10^4 <= starti < endi <= 5 * 10^4`

## Solution

```cpp
/* 1. Sort the Intervals based on start Time 
   2. If new Interval overlaps with previous interval, increment the erase count
   3. On overlap, keep the interval with lowest end Time
   4. If no overlap, make this new interval as previous interval and move to next interval
*/

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int eraseCount = 0, previousIntervalIndex = 0;
        for(int intervalIndex = 1; intervalIndex < intervals.size(); intervalIndex++)
        {
            if(intervals[intervalIndex][0] < intervals[previousIntervalIndex][1] ) // overlap
            {
                eraseCount++;
                if(intervals[intervalIndex][1] < intervals[previousIntervalIndex][1])
                    previousIntervalIndex = intervalIndex;
            }
            else
                previousIntervalIndex = intervalIndex;
        } 
        return eraseCount;
    }
};
```
