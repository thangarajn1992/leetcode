# Leetcode 56 Merge Intervals

## Problem Statement

Given an array of `intervals` where `intervals[i] = [starti, endi]`, merge all overlapping intervals, and return _an array of the non-overlapping intervals that cover all the intervals in the input_.

**Example 1:**

```text
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
```

**Example 2:**

```text
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.
```

**Constraints:**

* `1 <= intervals.length <= 10^4`
* `intervals[i].length == 2`
* `0 <= starti <= endi <= 10^4`

## Solution

### Sort and Merge

```cpp
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged_intervals;
        merged_intervals.push_back(intervals[0]);
        for(int i = 1; i < intervals.size(); i++)
        {
            // No overlap
            if(merged_intervals.back()[1] < intervals[i][0]) 
                merged_intervals.push_back(intervals[i]);
            else if(merged_intervals.back()[1] < intervals[i][1])
                merged_intervals.back()[1] = intervals[i][1];
        }
        return merged_intervals;
    }
};
```

### Graph Approach \( Times out for bigger input \)

```cpp
class Solution {
public:
    map<vector<int>, vector<vector<int>>> graph;
    map<int, vector<vector<int>>> nodes_in_comp;
    set<vector<int>> visited;

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        // Build the graph where there exists undirected edge if intervals overlap
        for (vector<int> &interval1 : intervals) {
            for (vector<int> &interval2 : intervals) {
                if(interval1[0] <= interval2[1] && interval2[0] <= interval1[1])
                {
                    graph[interval1].push_back(interval2);
                    graph[interval2].push_back(interval1);
                }
            }
        }        
        // Build the number of connected components and intervals in them.
        int comp_number = 0;
        for (auto interval : intervals) {
            if (visited.find(interval) == visited.end()) {
                markComponentDFS(interval, comp_number);
                comp_number++;
            }
        }
        
        // for each component, merge all intervals into one interval.
        vector<vector<int>> merged;
        for (size_t comp = 0; comp < nodes_in_comp.size(); comp++) {
            vector<vector<int>>& nodes = nodes_in_comp[comp];
            
            int min_start = nodes[0][0];
            for (vector<int> &node : nodes) {
                min_start = min(min_start, node[0]);
            }
            int max_end = nodes[0][1];
            for (vector<int> &node : nodes) {
                max_end = max(max_end, node[1]);
            }            
            
            merged.push_back({min_start, max_end});
        }
        return merged;
    }
    
    // use depth-first search to mark all nodes in the same connected component
    // with the same integer.
    void markComponentDFS(vector<int>& start, int comp_number) {
        stack<vector<int>> stk;
        stk.push(start);

        while (!stk.empty()) {
            vector<int> node = stk.top();
            stk.pop();

            // not found
            if (visited.find(node) == visited.end()) {
                visited.insert(node);

                nodes_in_comp[comp_number].push_back(node);

                for (auto child : graph[node]) {
                    stk.push(child);
                }
            }
        }
    }
};
```

