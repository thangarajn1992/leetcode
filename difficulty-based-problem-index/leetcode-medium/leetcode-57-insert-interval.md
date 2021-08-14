# Leetcode 57 Insert Interval

## Problem Statement

[https://leetcode.com/problems/insert-interval/](https://leetcode.com/problems/insert-interval/)

Given a set of _non-overlapping_ intervals, insert a new interval into the intervals \(merge if necessary\).

You may assume that the intervals were initially sorted according to their start times.

**Example 1:**

```text
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]
```

**Example 2:**

```text
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
```

**Example 3:**

```text
Input: intervals = [], newInterval = [5,7]
Output: [[5,7]]
```

**Example 4:**

```text
Input: intervals = [[1,5]], newInterval = [2,3]
Output: [[1,5]]
```

**Example 5:**

```text
Input: intervals = [[1,5]], newInterval = [2,7]
Output: [[1,7]]
```

**Constraints:**

* `0 <= intervals.length <= 10^4`
* `intervals[i].length == 2`
* `0 <= intervals[i][0] <= intervals[i][1] <= 10^5`
* `intervals` is sorted by `intervals[i][0]` in **ascending** order.
* `newInterval.length == 2`
* `0 <= newInterval[0] <= newInterval[1] <= 10^5`

## Solution

```cpp
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> final_intervals;
        int i = 0;
        int start = newInterval[0], end = newInterval[1];
        for(; i < intervals.size(); i++)
        {
            if(intervals[i][1] < start)
            {
                // interval non-overlap with newInterval
                final_intervals.push_back(intervals[i]);
            }
            else if(intervals[i][1] >= start && end >= intervals[i][0])
            {
                // Overlapping Intervals
                start = min(intervals[i][0], start);
                end = max(intervals[i][1], end);
            }
            else if(intervals[i][0] > end) // Merging done
                break;
        }
        final_intervals.push_back({start, end});
        final_intervals.insert(final_intervals.end(), intervals.begin()+i, intervals.end());
        return final_intervals;     
    }
};
```

