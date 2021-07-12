# Leetcode 802 Find Eventual Safe States

## Problem Statement

[https://leetcode.com/problems/find-eventual-safe-states/](https://leetcode.com/problems/find-eventual-safe-states/)

We start at some node in a directed graph, and every turn, we walk along a directed edge of the graph. If we reach a terminal node \(that is, it has no outgoing directed edges\), we stop.

We define a starting node to be **safe** if we must eventually walk to a terminal node. More specifically, there is a natural number `k`, so that we must have stopped at a terminal node in less than `k` steps for **any choice of where to walk**.

Return _an array containing all the safe nodes of the graph_. The answer should be sorted in **ascending** order.

The directed graph has `n` nodes with labels from `0` to `n - 1`, where `n` is the length of `graph`. The graph is given in the following form: `graph[i]` is a list of labels `j` such that `(i, j)` is a directed edge of the graph, going from node `i` to node `j`.

**Example 1:** ![Illustration of graph](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/03/17/picture1.png)

```text
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Explanation: The given graph is shown above.
```

**Example 2:**

```text
Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
Output: [4]
```

**Constraints:**

* `n == graph.length`
* `1 <= n <= 10^4`
* `0 <= graph[i].length <= n`
* `graph[i]` is sorted in a strictly increasing order.
* The graph may contain self-loops.
* The number of edges in the graph will be in the range `[1, 4 * 10^4]`.

## Solution

```cpp
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), 0);
        vector<int> result;
        
        for(int i = 0; i < graph.size(); i++)
            if(dfs(i, color, graph))
                result.push_back(i);
        
        return result;
    }
    
    bool dfs(int node, vector<int>&color, vector<vector<int>>& graph)
    {
        if(color[node] > 0)
            return color[node] == 2;
        
        color[node] = 1;
        for(int neigh : graph[node])
        {
            if(color[neigh] == 2)
                continue;
            if(color[neigh] == 1 || dfs(neigh, color, graph) == false)
                return false;
        }
        // All paths lead to safe state
        color[node] = 2;
        return true;
    }
};
```

