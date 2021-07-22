# Leetcode 838 Push Dominoes

## Problem Statement

[https://leetcode.com/problems/push-dominoes/](https://leetcode.com/problems/push-dominoes/)

There are `n` dominoes in a line, and we place each domino vertically upright. In the beginning, we simultaneously push some of the dominoes either to the left or to the right.

After each second, each domino that is falling to the left pushes the adjacent domino on the left. Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.

When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.

For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.

You are given a string `dominoes` representing the initial state where:

* `dominoes[i] = 'L'`, if the `ith` domino has been pushed to the left,
* `dominoes[i] = 'R'`, if the `ith` domino has been pushed to the right, and
* `dominoes[i] = '.'`, if the `ith` domino has not been pushed.

Return _a string representing the final state_.

**Example 1:**

```text
Input: dominoes = "RR.L"
Output: "RR.L"
Explanation: 
The first domino expends no additional force on the second domino.
```

**Example 2:** ![](https://s3-lc-upload.s3.amazonaws.com/uploads/2018/05/18/domino.png)

```text
Input: dominoes = ".L.R...LR..L.."
Output: "LL.RR.LLRRLL.."
```

**Constraints:**

* `n == dominoes.length`
* `1 <= n <= 10^5`
* `dominoes[i]` is either `'L'`, `'R'`, or `'.'`.

## Solution

### Who is closer to me, affects me more

```cpp
class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        int L_distance[n];
        int R_distance[n];  
        
        // We calculate distance of closest L and R for each domino
        // Whoever has close distance will affect  that domino
        int distance = INT32_MAX; // INTMAX means longest distance
        
        // Calculating R distance for each domino
        for(int domino = 0; domino < n; domino++){
            if(distance == INT32_MAX)
            {
                if(dominoes[domino] == 'R'){
                    distance = 0;
                }
            }
            else
            {
                distance++;
                if(dominoes[domino]=='R'){
                    distance = 0;
                }
                if(dominoes[domino]=='L'){
                    distance = INT32_MAX;
                }
            }
            R_distance[domino] = distance;
        }
        
        // Calculating L distance for each domino
        distance = INT32_MAX;
        for(int domino = n-1; domino >=0; domino--){
               if(distance == INT32_MAX){
                if(dominoes[domino] == 'L'){
                    distance = 0;
                }
            }
            else{
                distance++;
                if(dominoes[domino]=='L'){
                    distance = 0;
                }
                if(dominoes[domino] =='R'){
                    distance = INT32_MAX;
                }
            }
            L_distance[domino] = distance;
        }
       
        for(int domino = 0; domino < n; domino++){
            if(L_distance[domino] < R_distance[domino]){
                dominoes[domino] = 'L';
            }
            else if(L_distance[domino] > R_distance[domino]){
                dominoes[domino] = 'R';
            }
        }
        return dominoes;
    }
};
```

### My own working code with same execution time

```cpp
class Solution {
public:
    string pushDominoes(string dominoes) {
        int last_r = -1;
        bool new_R_found = false;
        for(int i = 0; i < dominoes.size(); i++)
        {
            if(dominoes[i] == 'R')
            {
                // fill everything between last R and current R with R
                // R....R case
                if(new_R_found) 
                    for(int j = i; j > last_r; j--)
                        dominoes[j] = 'R';
    
                last_r = i;
                new_R_found = true;
            }
            else if(dominoes[i] == 'L')
            {
                // L....L  and ....L case
                if(new_R_found == false)  
                {
                    for(int j = i-1; j >= 0 && dominoes[j] == '.'; j--)
                        dominoes[j] = 'L';
                }
                else // R....L case
                {
                    // from last_r to this L, 
                    // first half will be R  , second half will be L
                    int indexes_falling = (i - last_r - 1)/2;
                    for(int j = last_r+1; j < last_r+1+indexes_falling; j++)
                        dominoes[j] = 'R';
                    
                    for(int j = i-1; j > i-1-indexes_falling; j--)
                        dominoes[j] = 'L';
                }
                new_R_found = false;
            }           
        }
        if(new_R_found)  // R.... case
            for(int i = last_r; i < dominoes.size(); i++)
                    dominoes[i] = 'R';
        
        return dominoes;
    }
};
```

