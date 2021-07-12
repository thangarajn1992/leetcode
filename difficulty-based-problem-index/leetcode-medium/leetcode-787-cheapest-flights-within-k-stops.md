# Leetcode 787 Cheapest Flights Within K Stops

## Problem Statement

[https://leetcode.com/problems/cheapest-flights-within-k-stops/](https://leetcode.com/problems/cheapest-flights-within-k-stops/)

There are `n` cities connected by some number of flights. You are given an array `flights` where `flights[i] = [fromi, toi, pricei]` indicates that there is a flight from city `fromi` to city `toi` with cost `pricei`.

You are also given three integers `src`, `dst`, and `k`, return _**the cheapest price** from_ `src` _to_ `dst` _with at most_ `k` _stops._ If there is no such route, return `-1`.

**Example 1:** ![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/02/16/995.png)

```text
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 1
Output: 200
Explanation: The graph is shown.
The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red 
in the picture.
```

**Example 2:** ![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/02/16/995.png)

```text
Input: n = 3, flights = [[0,1,100],[1,2,100],[0,2,500]], src = 0, dst = 2, k = 0
Output: 500
Explanation: The graph is shown.
The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue 
in the picture.
```

**Constraints:**

* `1 <= n <= 100`
* `0 <= flights.length <= (n * (n - 1) / 2)`
* `flights[i].length == 3`
* `0 <= fromi, toi < n`
* `fromi != toi`
* `1 <= pricei <= 10^4`
* There will not be any multiple flights between two cities.
* `0 <= src, dst, k < n`
* `src != dst`

## Solution

```cpp
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        // populating adjacency list for edges
        vector<pair<int, int>> adj[n];
        for(vector<int> it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        // queue which stores array[price, vertex, edge_steps]
        // We sort the queue based on the price first
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
        
        vector<int> dist(n, INT_MAX); // No. of stops
        pq.push({0, src, 0});
        
        
        while(!pq.empty()) {
            auto [price, vertex, edge_steps] = pq.top(); pq.pop();
            
            // This is the vertex we need
            if(vertex == dst) 
                return price;
            
            // We already crossed the limit of stops, don't consider this path
            if(edge_steps > k) 
                continue;
            
            // If we have already found better way, skip processing this path
            if(dist[vertex] != INT_MAX) {
                if(dist[vertex] < edge_steps) 
                    continue;
            }
            
            // We found better path, update the distance for this vertex
            dist[vertex] = edge_steps;
            
            // Update price for its neighbors and push them into queue
            for(pair<int, int> v : adj[vertex]) {
                pq.push({price + v.second, v.first, edge_steps+1});
            }
        }
        return -1;
    }
};
```

