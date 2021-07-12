# Leetcode 1928 Minimum Cost to Reach Destination in Time

## Problem Statement

[https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/](https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/)

There is a country of `n` cities numbered from `0` to `n - 1` where **all the cities are connected** by bi-directional roads. The roads are represented as a 2D integer array `edges` where `edges[i] = [xi, yi, timei]` denotes a road between cities `xi` and `yi` that takes `timei` minutes to travel. There may be multiple roads of differing travel times connecting the same two cities, but no road connects a city to itself.

Each time you pass through a city, you must pay a passing fee. This is represented as a **0-indexed** integer array `passingFees` of length `n` where `passingFees[j]` is the amount of dollars you must pay when you pass through city `j`.

In the beginning, you are at city `0` and want to reach city `n - 1` in `maxTime` **minutes or less**. The **cost** of your journey is the **summation of passing fees** for each city that you passed through at some moment of your journey \(**including** the source and destination cities\).

Given `maxTime`, `edges`, and `passingFees`, return _the **minimum cost** to complete your journey, or_ `-1` _if you cannot complete it within_ `maxTime` _minutes_.

**Example 1:**

![](https://assets.leetcode.com/uploads/2021/06/04/leetgraph1-1.png)

```text
Input: maxTime = 30, edges = [[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]], passingFees = [5,1,2,20,20,3]
Output: 11
Explanation: 
The path to take is 0 -> 1 -> 2 -> 5, which takes 30 minutes and has $11 worth of 
passing fees.
```

**Example 2:**

![](https://assets.leetcode.com/uploads/2021/06/04/copy-of-leetgraph1-1.png)

```text
Input: maxTime = 29, edges = [[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]], passingFees = [5,1,2,20,20,3]
Output: 48
Explanation: 
The path to take is 0 -> 3 -> 4 -> 5, which takes 26 minutes and has $48 worth of passing
fees. You cannot take path 0 -> 1 -> 2 -> 5 since it would take too long.
```

**Example 3:**

```text
Input: maxTime = 25, edges = [[0,1,10],[1,2,10],[2,5,10],[0,3,1],[3,4,10],[4,5,15]], passingFees = [5,1,2,20,20,3]
Output: -1
Explanation: There is no way to reach city 5 from city 0 within 25 minutes.
```

**Constraints:**

* `1 <= maxTime <= 1000`
* `n == passingFees.length`
* `2 <= n <= 1000`
* `n - 1 <= edges.length <= 1000`
* `0 <= xi, yi <= n - 1`
* `1 <= timei <= 1000`
* `1 <= passingFees[j] <= 1000` 
* The graph may contain multiple edges between two nodes.
* The graph does not contain self loops.

## Solution

### Dijkstra's Based Approach

```cpp
class Solution {
public:
    vector<array<int, 3>> adj[1001];
    vector<int>cost;
    vector<int>time;

    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& fee) {
        int n = fee.size();
        
        cost.resize(1001, INT_MAX);
        time.resize(1001, INT_MAX);
        
        for (vector<int>&edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2], fee[edge[1]]});
            adj[edge[1]].push_back({edge[0], edge[2], fee[edge[0]]});
        }
        
        cost[0] = fee[0];
        time[0] = 0;
        
        int ans = dijkstra(0, n-1, maxTime);
        
        return ans == INT_MAX ? -1 : ans ;
    }
    
    int dijkstra(int src, int dest, int maxTime) {
        
        priority_queue<array<int,3>, vector<array<int, 3>>, greater<array<int,3>>> pq;
        pq.push({cost[src], time[src], src});
        
        while (pq.empty() == 0) {
            auto[c, t, v] = pq.top(); pq.pop();

            if(v == dest) 
                return c;  //this is important and makes similar to actual dijkstra's
            
            for (int i = 0; i < adj[v].size(); i++) 
            {
                if (t + adj[v][i][1] <= maxTime) 
                {
				    // if cost will decrease or time will decrease, push it into queue
                    if (cost[adj[v][i][0]] > c + adj[v][i][2] or time[adj[v][i][0]] > t + adj[v][i][1] ) 
                    {
                        cost[adj[v][i][0]] = c + adj[v][i][2];
                        time[adj[v][i][0]] = t + adj[v][i][1];                    
                        pq.push({cost[adj[v][i][0]], time[adj[v][i][0]], adj[v][i][0]});
                    }
                }
            }
        }
        return INT_MAX;
    }
};
```

