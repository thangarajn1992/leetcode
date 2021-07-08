# Leetcode 399 Evaluate Division

## Problem Statement

[https://leetcode.com/problems/evaluate-division/](https://leetcode.com/problems/evaluate-division/)

You are given an array of variable pairs `equations` and an array of real numbers `values`, where `equations[i] = [Ai, Bi]` and `values[i]` represent the equation `Ai / Bi = values[i]`. Each `Ai` or `Bi` is a string that represents a single variable.

You are also given some `queries`, where `queries[j] = [Cj, Dj]` represents the `jth` query where you must find the answer for `Cj / Dj = ?`.

Return _the answers to all queries_. If a single answer cannot be determined, return `-1.0`.

**Note:** The input is always valid. You may assume that evaluating the queries will not result in division by zero and that there is no contradiction.

**Example 1:**

```text
Input: equations = [["a","b"],["b","c"]], values = [2.0,3.0], 
       queries = [["a","c"],["b","a"],["a","e"],["a","a"],["x","x"]]
Output: [6.00000,0.50000,-1.00000,1.00000,-1.00000]
Explanation: 
Given: a / b = 2.0, b / c = 3.0
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ?
return: [6.0, 0.5, -1.0, 1.0, -1.0 ]
```

**Example 2:**

```text
Input: equations = [["a","b"],["b","c"],["bc","cd"]], values = [1.5,2.5,5.0], 
       queries = [["a","c"],["c","b"],["bc","cd"],["cd","bc"]]
Output: [3.75000,0.40000,5.00000,0.20000]
```

**Example 3:**

```text
Input: equations = [["a","b"]], values = [0.5], 
       queries = [["a","b"],["b","a"],["a","c"],["x","y"]]
Output: [0.50000,2.00000,-1.00000,-1.00000]
```

**Constraints:**

* `1 <= equations.length <= 20`
* `equations[i].length == 2`
* `1 <= Ai.length, Bi.length <= 5`
* `values.length == equations.length`
* `0.0 < values[i] <= 20.0`
* `1 <= queries.length <= 20`
* `queries[i].length == 2`
* `1 <= Cj.length, Dj.length <= 5`
* `Ai, Bi, Cj, Dj` consist of lower case English letters and digits.

## Solution

### My Graph Approach

```cpp
struct edge{
    string name;
    double value;
};

class node
{
public:
    string name;
    vector<struct edge *> adj;
    node(string name)  { this->name = name; }
};

class Solution {
public:
    map<string, node*> name_node_map;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        // Create map with necessary nodes and edges
        for(int equation = 0; equation < equations.size(); equation++)
        {
            if(name_node_map.find(equations[equation][0]) == name_node_map.end())
                name_node_map[equations[equation][0]] = new node(equations[equation][0]);
            if(name_node_map.find(equations[equation][1]) == name_node_map.end())
                name_node_map[equations[equation][1]] = new node(equations[equation][1]);
            
            struct edge *e1 = new struct edge;
            e1->name = equations[equation][1];
            e1->value = values[equation];
            name_node_map[equations[equation][0]]->adj.push_back(e1);
            
            struct edge *e2 = new struct edge;
            e2->name = equations[equation][0];
            e2->value = 1 / values[equation];
            name_node_map[equations[equation][1]]->adj.push_back(e2);
        }
        
        vector<double> result(queries.size(), -1);
        
        for(int query = 0; query < queries.size(); query++)
        {
            unordered_set<string> visited;
            node *src = name_node_map[queries[query][0]];
            node *dst = name_node_map[queries[query][1]];
            if(src != nullptr && dst != nullptr)
            {
                if(src == dst)
                    result[query] = double(1);
                else
                    result[query] = BFS(src, dst, visited);
            }  
        }
        return result;
    }
    
    double BFS(node* src, node* dst, unordered_set<string>&visited)
    {
        visited.insert(src->name);
        for(int neighbor = 0; neighbor < src->adj.size(); neighbor++)
        {
            if(!visited.count(src->adj[neighbor]->name))
            {
            node *neigh = name_node_map[src->adj[neighbor]->name];
            if(neigh == dst)
                return src->adj[neighbor]->value;
            double val = BFS(neigh, dst, visited);
            if(val != -1)
                return val * src->adj[neighbor]->value;
            }
        }
        return -1;
    }
};
```



