# Leetcode 743 Network Delay Time

## Problem Statement

[https://leetcode.com/problems/network-delay-time/](https://leetcode.com/problems/network-delay-time/)

You are given a network of `n` nodes, labeled from `1` to `n`. You are also given `times`, a list of travel times as directed edges `times[i] = (ui, vi, wi)`, where `ui` is the source node, `vi` is the target node, and `wi` is the time it takes for a signal to travel from source to target.

We will send a signal from a given node `k`. Return the time it takes for all the `n` nodes to receive the signal. If it is impossible for all the `n` nodes to receive the signal, return `-1`.

**Example 1:** ![](https://assets.leetcode.com/uploads/2019/05/23/931_example_1.png)

```text
Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
```

**Example 2:**

```text
Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
```

**Example 3:**

```text
Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
```

**Constraints:**

* `1 <= k <= n <= 100`
* `1 <= times.length <= 6000`
* `times[i].length == 3`
* `1 <= ui, vi <= n`
* `ui != vi`
* `0 <= wi <= 100`
* All the pairs `(ui, vi)` are **unique**. \(i.e., no multiple edges.\)

## Solution

### My Dijkstra's Shortest Path Approach

```cpp
struct edge {
    int neighbor;
    int time_taken;
};

class Graph {
public:
    int V;
    vector<vector<struct edge*>> adj;
    
    Graph(int V)
    {
        this->V = V;
        this->adj.resize(V);
        for(int i = 0; i < V; i++)
            this->adj[i] = {};
    }
    
    void add_edge(int u, int v, int time_taken)
    {
        struct edge *e = new struct edge;
        e->neighbor = v;
        e->time_taken = time_taken;
        adj[u].push_back(e);
    }
};

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Create Graph and add edges
        Graph G(n+1);
        for(vector<int>& time : times)
            G.add_edge(time[0], time[1], time[2]);
        
        return find_max_distance_with_dsp(G, n, k);
    }
    
    int find_max_distance_with_dsp(Graph &G, int total_nodes, int src)
    {
        vector<int> dist(total_nodes+1, INT_MAX);
        vector<bool> sp_found(total_nodes+1, false);
        
        dist[0] = 0;
        dist[src] = 0;
        
        for(int count = 1; count < total_nodes; count++)
        {
            //Find the next node with min distance to process
            int min_node, min_dist = INT_MAX;
            for(int i = 1; i <= total_nodes; i++)
            {
                if(sp_found[i] == false && dist[i] < min_dist)
                {
                    min_dist = dist[i];
                    min_node = i;
                }
            }
            
            sp_found[min_node] = true;
            
            // Update dist for the neighbors of the node selected
            vector<struct edge*> &my_adj = G.adj[min_node];
            for(int i = 0; i < my_adj.size(); i++)
            {
                if(sp_found[my_adj[i]->neighbor] == false && dist[min_node] != INT_MAX &&
                   dist[my_adj[i]->neighbor] > dist[min_node] + my_adj[i]->time_taken)
                    dist[my_adj[i]->neighbor] = dist[min_node] + my_adj[i]->time_taken;
            }
        }
        
        int maxi = *max_element(dist.begin(), dist.end());
        return maxi != INT_MAX ? maxi : -1;
    }
};
```

