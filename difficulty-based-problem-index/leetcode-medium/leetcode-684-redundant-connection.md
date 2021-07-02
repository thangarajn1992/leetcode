# Leetcode 684 Redundant Connection

[https://leetcode.com/problems/redundant-connection/](https://leetcode.com/problems/redundant-connection/)

In this problem, a tree is an **undirected graph** that is connected and has no cycles.

You are given a graph that started as a tree with `n` nodes labeled from `1` to `n`, with one additional edge added. The added edge has two **different** vertices chosen from `1` to `n`, and was not an edge that already existed. The graph is represented as an array `edges` of length `n` where `edges[i] = [ai, bi]` indicates that there is an edge between nodes `ai` and `bi` in the graph.

Return _an edge that can be removed so that the resulting graph is a tree of_ `n` _nodes_. If there are multiple answers, return the answer that occurs last in the input.

**Example 1:** ![](https://assets.leetcode.com/uploads/2021/05/02/reduntant1-1-graph.jpg)

```text
Input: edges = [[1,2],[1,3],[2,3]]
Output: [2,3]
```

**Example 2:** ![](https://assets.leetcode.com/uploads/2021/05/02/reduntant1-2-graph.jpg)

```text
Input: edges = [[1,2],[2,3],[3,4],[1,4],[1,5]]
Output: [1,4]
```

**Constraints:**

* `n == edges.length`
* `3 <= n <= 1000`
* `edges[i].length == 2`
* `1 <= ai < bi <= edges.length`
* `ai != bi`
* There are no repeated edges.
* The given graph is connected.

## Solution

### My Approach \( Basic DFS while adding each edge \)

```cpp
class Solution {
public:
    set<int> seen; 
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<vector<int>> graph(edges.size() + 1, vector<int>());
        
        for(vector<int> &edge : edges) 
        {
            seen.clear();
            if(graph[edge[0]].size() && graph[edge[1]].size() &&
                dfs_is_cycle(graph, edge[0], edge[1])) {
                return edge;
            }
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        return {-1,-1};
    }
    bool dfs_is_cycle(vector<vector<int>> &graph, int start, int end)
    {
        // If we can reach end from start already, then this edge causes loop
        if(!seen.count(start))
        {
            seen.insert(start);
            for(int neighbor : graph[start])
                if(neighbor == end || dfs_is_cycle(graph, neighbor, end))
                    return true;
        }
        return false;
    }
};
```

### Disjoint Set Union \(DSU\) Approach

A DSU data structure can be used to maintain knowledge of the connected components of a graph, and query for them quickly. In particular, we would like to support two operations:

* `dsu.find(node x)`, which outputs a unique id so that two nodes have the same id if and only if they are in the same connected component, and:
* `dsu.union(node x, node y)`, which draws an edge `(x, y)` in the graph, connecting the components with id `find(x)` and `find(y)` together.

To achieve this, we keep track of `parent`, which remembers the `id` of a larger node in the same connected component. If the node is it's own parent, we call this the _leader_ of that connected component.

```cpp
class Solution {
public:
    int parent[1001];
    int findParent(int vertex)
    {
        if(vertex == parent[vertex])
            return vertex;
        return parent[vertex] = findParent(parent[vertex]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) 
    {
        for(int vertex_num = 1; vertex_num <= edges.size(); vertex_num++)
            parent[vertex_num] = vertex_num;
        for(vector<int> &edge : edges)
        {
            int my_parent = findParent(edge[0]);
            int neighbor_parent = findParent(edge[1]);
            if(my_parent != neighbor_parent) 
            // Merge them into single connected component.
                parent[my_parent] = neighbor_parent;
            else
                return edge;
        }
        return {-1,-1}; // We won't reach here because of constraints in Problem statement.
    }
};
```

