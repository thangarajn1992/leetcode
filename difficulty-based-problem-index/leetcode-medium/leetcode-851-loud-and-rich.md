# Leetcode 851 Loud and Rich

## Problem Statement

[https://leetcode.com/problems/loud-and-rich/](https://leetcode.com/problems/loud-and-rich/)

In a group of N people \(labelled `0, 1, 2, ..., N-1`\), each person has different amounts of money, and different levels of quietness.

For convenience, we'll call the person with label `x`, simply "person `x`".

We'll say that `richer[i] = [x, y]` if person `x` definitely has more money than person `y`.  Note that `richer` may only be a subset of valid observations.

Also, we'll say `quiet[x] = q` if person x has quietness `q`.

Now, return `answer`, where `answer[x] = y` if `y` is the least quiet person \(that is, the person `y` with the smallest value of `quiet[y]`\), among all people who definitely have equal to or more money than person `x`.

**Example 1:**

```text
Input: richer = [[1,0],[2,1],[3,1],[3,7],[4,3],[5,3],[6,3]], quiet = [3,2,5,4,6,1,7,0]
Output: [5,5,2,5,4,5,6,7]
Explanation: 
answer[0] = 5.
Person 5 has more money than 3, which has more money than 1, which has more money than 0.
The only person who is quieter (has lower quiet[x]) is person 7, but
it isn't clear if they have more money than person 0.

answer[7] = 7.
Among all people that definitely have equal to or more money than person 7
(which could be persons 3, 4, 5, 6, or 7), the person who is the quietest (has lower quiet[x])
is person 7.

The other answers can be filled out with similar reasoning.
```

**Note:**

1. `1 <= quiet.length = N <= 500`
2. `0 <= quiet[i] < N`, all `quiet[i]` are different.
3. `0 <= richer.length <= N * (N-1) / 2`
4. `0 <= richer[i][j] < N`
5. `richer[i][0] != richer[i][1]`
6. `richer[i]`'s are all different.
7. The observations in `richer` are all logically consistent.

## Solution

### My DFS Approach

```cpp
class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        
        // Directed edge will point from poor to rich
        vector<vector<int>> adj(quiet.size());
        
        for(vector<int>&compare : richer)
            adj[compare[1]].push_back(compare[0]);
        
        // DO DFS and find the quietest rich guy for each person
        vector<int> answer(quiet.size(), -1);
        for(int i = 0; i < quiet.size(); i++)
            if(answer[i] == -1)
                answer[i] = DFS(i, adj, quiet, answer);
            
        return answer; 
    }
    int DFS(int per, vector<vector<int>>&adj, vector<int>&quiet, vector<int>&answer)
    {
        int mini = quiet[per];
        int min_index = per;
        
        for(int next : adj[per])
        {
            if(answer[next] == - 1)
                answer[next] = DFS(next, adj, quiet, answer);
            if(quiet[answer[next]] < mini)
            {
                min_index = answer[next];
                mini = quiet[answer[next]];
            }               
        }
        return min_index;
    }
};
```

