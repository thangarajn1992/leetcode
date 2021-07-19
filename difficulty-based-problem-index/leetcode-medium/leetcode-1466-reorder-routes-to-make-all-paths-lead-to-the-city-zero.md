# Leetcode 1466 Reorder Routes to Make All Paths Lead to the City Zero

## Problem Statement

[https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/](https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/)

There are `n` cities numbered from `0` to `n - 1` and `n - 1` roads such that there is only one way to travel between two different cities \(this network form a tree\). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.

Roads are represented by `connections` where `connections[i] = [ai, bi]` represents a road from city `ai` to city `bi`.

This year, there will be a big event in the capital \(city `0`\), and many people want to travel to this city.

Your task consists of reorienting some roads such that each city can visit the city `0`. Return the **minimum** number of edges changed.

It's **guaranteed** that each city can reach city `0` after reorder.

**Example 1:** ![](https://assets.leetcode.com/uploads/2020/05/13/sample_1_1819.png)

```text
Input: n = 6, connections = [[0,1],[1,3],[2,3],[4,0],[4,5]]
Output: 3
Explanation: 
Change the direction of edges show in red such that each node can reach the node 0 (capital).
```

**Example 2:** ![](https://assets.leetcode.com/uploads/2020/05/13/sample_2_1819.png)

```text
Input: n = 5, connections = [[1,0],[1,2],[3,2],[3,4]]
Output: 2
Explanation: 
Change the direction of edges show in red such that each node can reach the node 0 (capital).
```

**Example 3:**

```text
Input: n = 3, connections = [[1,0],[2,0]]
Output: 0
```

**Constraints:**

* `2 <= n <= 5 * 10^4`
* `connections.length == n - 1`
* `connections[i].length == 2`
* `0 <= ai, bi <= n - 1`
* `ai != bi`

## Solution

```cpp
class Solution {
public:
    map<pair<int,int>, int> mp; // to store directions
    int minReorder(int n, vector<vector<int>>& connections) {
        // Consider edges as undirected, 
        // Do BFS, when we see outward edge, change its direction
        // Map is used to store the direction of each edge.
        
        // Construct the graph adjacency
        vector<vector<int>> adj(n);
        for(vector<int> connection : connections)
        {
            adj[connection[0]].push_back(connection[1]);
            adj[connection[1]].push_back(connection[0]);
            mp[{connection[0], connection[1]}] = 1;
        }
        
        // do BFS from 0
        int change_direction = 0;
        vector<int> visited(n, false);
        queue<int> q;
        visited[0] = true;
        q.push(0);
        while(q.empty() == false)
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                int city = q.front(); q.pop();
                for(int neigh : adj[city])
                {
                    if(visited[neigh] == false)
                    {
                        if(mp[{city,neigh}])
                            change_direction++;
                        visited[neigh] = true;
                        q.push(neigh);
                    }
                }
            }
        }
        return change_direction;
    }
};
```

