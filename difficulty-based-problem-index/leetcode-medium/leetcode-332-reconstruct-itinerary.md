# Leetcode 332 - Reconstruct Itinerary

## Problem Statement

You are given a list of airline `tickets` where `tickets[i] = [fromi, toi]` represent the departure and the arrival airports of one flight. Reconstruct the itinerary in order and return it.

All of the tickets belong to a man who departs from `"JFK"`, thus, the itinerary must begin with `"JFK"`. If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string.

* For example, the itinerary `["JFK", "LGA"]` has a smaller lexical order than `["JFK", "LGB"]`.

You may assume all tickets form at least one valid itinerary. You must use all the tickets once and only once.

**Example 1:** ![](https://assets.leetcode.com/uploads/2021/03/14/itinerary1-graph.jpg)

```text
Input: tickets = [["MUC","LHR"],["JFK","MUC"],["SFO","SJC"],["LHR","SFO"]]
Output: ["JFK","MUC","LHR","SFO","SJC"]
```

**Example 2:** ![](https://assets.leetcode.com/uploads/2021/03/14/itinerary2-graph.jpg)

```text
Input: tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Output: ["JFK","ATL","JFK","SFO","ATL","SFO"]
Explanation: 
Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"] but it is larger
in lexical order.
```

**Constraints:**

* `1 <= tickets.length <= 300`
* `tickets[i].length == 2`
* `fromi.length == 3`
* `toi.length == 3`
* `fromi` and `toi` consist of uppercase English letters.
* `fromi != toi`

## Solution

### My Approach - Graph based

```cpp
/* Graph Node definition */
class node{
public:
    string name;
    vector<node*> adj;
    vector<bool> visited;
    node(string name)
    {
        this->name = name;
        this->adj = {};
    }
};

// Sort function to sort neighbors in lexical order
bool my_sort(node* a, node* b)
{ 
    return a->name < b->name;
}

class Solution {
public:
    int total_edges;  // No. of edges + 1 will be the path length
    vector<string> itinerary; // Resultant itinerary
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Map of node name to node pointer
        map<string, node*> name_node_map; 
        
        // Adding edges in the graph
        for(vector<string> &ticket : tickets)
        {
            if(name_node_map.find(ticket[0]) == name_node_map.end())
                name_node_map[ticket[0]] = new node(ticket[0]);
            
            if(name_node_map.find(ticket[1]) == name_node_map.end())
                name_node_map[ticket[1]] = new node(ticket[1]);
            
            name_node_map[ticket[0]]->adj.push_back(name_node_map[ticket[1]]);
            total_edges++;
        }
        
        // Sorting neighbors in lexical order
        for(auto node_itr = name_node_map.begin(); node_itr != name_node_map.end(); node_itr++)
        {
            node* n = node_itr->second;
            sort(n->adj.begin(), n->adj.end(), my_sort);
            n->visited.resize(n->adj.size(),false);
        }
        
        DFS(name_node_map["JFK"]);
        return itinerary;
    }
    bool DFS(node* node1)
    {
        itinerary.push_back(node1->name);
        
        // Success Condition
        if(total_edges + 1 == itinerary.size())
            return true;
        
        // Start from lexical order neighbors and see if there is a way
        // to cover all edges 
        for(int i = 0; i < node1->adj.size(); i++)
        {
            if(node1->visited[i] == false)
            {
                node1->visited[i] = true;
                if(DFS(node1->adj[i]))
                    return true;
                // We will make use of this node later, so reset it to NULL
                node1->visited[i] = false;
            }
        }
        // Not possible, remove this node from itinerary
        itinerary.pop_back();
        return false;
    }
};
```

