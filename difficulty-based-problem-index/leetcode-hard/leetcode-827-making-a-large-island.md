# Leetcode 827 Making A Large Island

## Problem Statement

[https://leetcode.com/problems/making-a-large-island/](https://leetcode.com/problems/making-a-large-island/)

You are given an `n x n` binary matrix `grid`. You are allowed to change **at most one** `0` to be `1`.

Return _the size of the largest **island** in_ `grid` _after applying this operation_.

An **island** is a 4-directionally connected group of `1`s.

**Example 1:**

```text
Input: grid = [[1,0],[0,1]]
Output: 3
Explanation: 
Change one 0 to 1 and connect two 1s, then we get an island with area = 3.
```

**Example 2:**

```text
Input: grid = [[1,1],[1,0]]
Output: 4
Explanation: 
Change the 0 to 1 and make the island bigger, only one island with area = 4.
```

**Example 3:**

```text
Input: grid = [[1,1],[1,1]]
Output: 4
Explanation: 
Can't change any 0 to 1, only one island with area = 4.
```

**Constraints:**

* `n == grid.length`
* `n == grid[i].length`
* `1 <= n <= 500`
* `grid[i][j]` is either `0` or `1`.

## Solution

#### Approach

For each group, fill it with value `index` and remember it's size as `area[index] = dfs(...)`.

Then for each `0`, look at the neighboring group ids `seen` and add the area of those groups, plus 1 for the `0` we are toggling. This gives us a candidate answer, and we take the maximum.

To solve the issue of having potentially no `0`, we take the maximum of the previously calculated areas.

```cpp
class Solution {
public:
    vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};
    
    int largestIsland(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int group_id = 2;
        unordered_map<int,int> total_ones_in_group_id;
        int maxArea = 0;
        
        // We Group 1s into different group-id
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if(grid[row][col] == 1){
                    int total_members = 0;
                    dfs(grid, row, col, group_id, total_members);
                    total_ones_in_group_id[group_id] = total_members;
                    group_id++;
                }
            }
        }
        
        queue<pair<int,int>> q;
        
        for(int row = 0; row < rows; row++){
            for(int col = 0; col < cols; col++){
                if(grid[row][col] == 0){
                    q.push({row, col});
                }
            }
        }
    
        if(q.empty()) 
            return rows*cols;
        
        while(!q.empty()){
            set<int> groups_visited_in_cur_bfs;
            int cur_row = q.front().first;
            int cur_col = q.front().second;
            q.pop();
            int area = 0;
            
            for(int d = 0; d < 4; d++){
                int next_row = cur_row + dir[d][0];
                int next_col = cur_col + dir[d][1];
                if(next_row < 0 || next_row >= rows || 
                   next_col < 0 || next_col >= cols || 
                   grid[next_row][next_col] < 2) 
                    continue;
                
                int group_id = grid[next_row][next_col];
                if(groups_visited_in_cur_bfs.count(group_id)) 
                    continue;
                area += total_ones_in_group_id[group_id];
                groups_visited_in_cur_bfs.insert(group_id);
             }
            maxArea = max(maxArea, area+1);
        }
        return maxArea;
    }
    
    void dfs(vector<vector<int>>& grid, int row, int col, int group_id, int &total_members){
        grid[row][col] = group_id;
        total_members++;
        for(int d = 0; d < 4; d++){
            int next_row = row + dir[d][0];
            int next_col = col + dir[d][1];
            if(next_row < 0 || next_row >= grid.size() || 
               next_col < 0 || next_col >= grid[0].size() || 
               grid[next_row][next_col] != 1) 
                continue;
            
            dfs(grid, next_row, next_col, group_id, total_members);
        }
    } 
};
```

