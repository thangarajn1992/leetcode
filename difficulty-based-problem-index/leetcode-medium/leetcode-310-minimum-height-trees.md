# Leetcode 310 Minimum Height Trees

[https://leetcode.com/problems/minimum-height-trees/](https://leetcode.com/problems/minimum-height-trees/)

A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

Given a tree of `n` nodes labelled from `0` to `n - 1`, and an array of `n - 1` `edges` where `edges[i] = [ai, bi]` indicates that there is an undirected edge between the two nodes `ai` and `bi` in the tree, you can choose any node of the tree as the root. When you select a node `x` as the root, the result tree has height `h`. Among all possible rooted trees, those with minimum height \(i.e. `min(h)`\)  are called **minimum height trees** \(MHTs\).

Return _a list of all **MHTs'** root labels_. You can return the answer in **any order**.

The **height** of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

**Example 1:** ![](https://assets.leetcode.com/uploads/2020/09/01/e1.jpg)

```text
Input: n = 4, edges = [[1,0],[1,2],[1,3]]
Output: [1]
Explanation: 
As shown, the height of the tree is 1 when the root is the node with label 1 which is the
only MHT.
```

**Example 2:** ![](https://assets.leetcode.com/uploads/2020/09/01/e2.jpg)

```text
Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
Output: [3,4]
```

**Example 3:**

```text
Input: n = 1, edges = []
Output: [0]
```

**Example 4:**

```text
Input: n = 2, edges = [[0,1]]
Output: [0,1]
```

**Constraints:**

* `1 <= n <= 2 * 10^4`
* `edges.length == n - 1`
* `0 <= ai, bi < n`
* `ai != bi`
* All the pairs `(ai, bi)` are distinct.
* The given input is **guaranteed** to be a tree and there will be **no repeated** edges.

### Explanation:

> For the tree-alike graph, the number of centroids is no more than 2.

If the nodes form a chain, it is intuitive to see that the above statement holds, which can be broken into the following two cases:

* If the number of nodes is even, then there would be two centroids.
* If the number of nodes is odd, then there would be only one centroid.

![example of centroids](https://leetcode.com/problems/minimum-height-trees/Figures/310/310_1_2_centroids.png)

For the rest of cases, we could prove by _**contradiction**_. Suppose that we have 3 centroids in the graph, if we remove all the non-centroid nodes in the graph, then the 3 centroids nodes must form a _triangle_ shape, as follows:

![triangle](https://leetcode.com/problems/minimum-height-trees/Figures/310/310_triangle.png)

Because these centroids are equally important to each other, and they should equally close to each other as well. If any of the edges that is missing from the triangle, then the 3 centroids would be reduced down to a single centroid.

However, the triangle shape forms a _cycle_ which is _**contradicted**_ to the condition that there is no cycle in our tree-alike graph. Similarly, for any of the cases that have more than 2 centroids, they must form a cycle among the centroids, which is contradicted to our condition.

Therefore, **there cannot be more than 2 centroids in a tree-alike graph.**

## Solution

```cpp
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)
            return vector<int>{0};    
        
        vector<vector<int>> adj(n, vector<int>());
        for(vector<int> edge : edges)
        {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        
        vector<int> leaves;
        for(int node = 0; node < n; node++)
        {
            if(adj[node].size() == 1) // leaf node
                leaves.push_back(node);
        }
        int remaining_nodes = n;
        while(remaining_nodes > 2)
        {
            remaining_nodes -= leaves.size();
            vector<int> new_leaves;
            for(int &leaf : leaves)
            {
                // Remove the single edge towards this leaf
                int neighbor = adj[leaf].front(); adj[leaf].clear();
                adj[neighbor].erase(find(adj[neighbor].begin(), adj[neighbor].end(), leaf));
                if(adj[neighbor].size() == 1)
                    new_leaves.push_back(neighbor);
            }
            leaves = new_leaves;
        }
        return leaves;
    }
};
```

