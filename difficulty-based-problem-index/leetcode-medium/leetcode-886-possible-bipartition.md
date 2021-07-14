# Leetcode 886 Possible Bipartition

## Problem Statement

[https://leetcode.com/problems/possible-bipartition/](https://leetcode.com/problems/possible-bipartition/)

Given a set of `n` people \(numbered `1, 2, ..., n`\), we would like to split everyone into two groups of **any** size.

Each person may dislike some other people, and they should not go into the same group. 

Formally, if `dislikes[i] = [a, b]`, it means it is not allowed to put the people numbered `a` and `b` into the same group.

Return `true` if and only if it is possible to split everyone into two groups in this way

**Example 1:**

```text
Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
Output: true
Explanation: group1 [1,4], group2 [2,3]
```

**Example 2:**

```text
Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
Output: false
```

**Example 3:**

```text
Input: n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
Output: false
```

**Constraints:**

* `1 <= n <= 2000`
* `0 <= dislikes.length <= 10000`
* `dislikes[i].length == 2`
* `1 <= dislikes[i][j] <= n`
* `dislikes[i][0] < dislikes[i][1]`
* There does not exist `i != j` for which `dislikes[i] == dislikes[j]`.

## Solution

### My Bipartite BFS Approach

```cpp
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n+1);
        for(vector<int> &edge: dislikes)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        // Similar to BiPartite Problem
        // DO BFS and try to color each node 
        // If two nodes of same edge has same color, return false
        vector<int> color(n+1, -1);
        queue<int> q;
        
        for(int i = 1; i <= n; i++) // for disconnected graph
        {
            if(color[i] == -1)
            {
                color[i] = 0;
                q.push(i);
                
                while(q.empty() == false)
                {
                    int node = q.front(); q.pop();
                    for(int j = 0; j < adj[node].size(); j++)
                    {
                        if(color[adj[node][j]] == -1)
                        {
                            color[adj[node][j]] = color[node] ? 0 : 1;                                                                   q.push(adj[node][j]);
                        }
                        else if(color[adj[node][j]] == color[node])
                            return false;
                    }        
                }
            }
        }
        return true;
    }
};
```

