# Leetcode 797 All Paths From Source to Target

## Problem Statement

[https://leetcode.com/problems/all-paths-from-source-to-target/](https://leetcode.com/problems/all-paths-from-source-to-target/)

Given a directed acyclic graph \(**DAG**\) of `n` nodes labeled from 0 to n - 1, find all possible paths from node `0` to node `n - 1`, and return them in any order.

The graph is given as follows: `graph[i]` is a list of all nodes you can visit from node `i` \(i.e., there is a directed edge from node `i` to node `graph[i][j]`\).

**Example 1:** ![](https://assets.leetcode.com/uploads/2020/09/28/all_1.jpg)

```text
Input: graph = [[1,2],[3],[3],[]]
Output: [[0,1,3],[0,2,3]]
Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
```

**Example 2:** ![](https://assets.leetcode.com/uploads/2020/09/28/all_2.jpg)

```text
Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]
```

**Example 3:**

```text
Input: graph = [[1],[]]
Output: [[0,1]]
```

**Example 4:**

```text
Input: graph = [[1,2,3],[2],[3],[]]
Output: [[0,1,2,3],[0,2,3],[0,3]]
```

**Example 5:**

```text
Input: graph = [[1,3],[2],[3],[]]
Output: [[0,1,2,3],[0,3]]
```

**Constraints:**

* `n == graph.length`
* `2 <= n <= 15`
* `0 <= graph[i][j] < n`
* `graph[i][j] != i` \(i.e., there will be no self-loops\).
* The input graph is **guaranteed** to be a **DAG**.

## Solution

```cpp
class Solution {
public:
    vector<vector<int>> paths;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        DFS(0, graph.size()-1, {}, graph);
        return paths;
    }
    
    void DFS(int src, int dst, vector<int> path, vector<vector<int>>&graph)
    {
        path.push_back(src);
        if(src == dst)
        {
            paths.push_back(path);
            return;
        }
        
        for(int &neigh : graph[src])
            DFS(neigh, dst, path, graph);
    }
};
```

