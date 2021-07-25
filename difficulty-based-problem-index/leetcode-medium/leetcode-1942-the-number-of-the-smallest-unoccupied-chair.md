# Leetcode 1942 The Number of the Smallest Unoccupied Chair

## Problem Statement

[https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/](https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/)

There is a party where `n` friends numbered from `0` to `n - 1` are attending. There is an **infinite** number of chairs in this party that are numbered from `0` to `infinity`. When a friend arrives at the party, they sit on the unoccupied chair with the **smallest number**.

* For example, if chairs `0`, `1`, and `5` are occupied when a friend comes, they will sit on chair number `2`.

When a friend leaves the party, their chair becomes unoccupied at the moment they leave. If another friend arrives at that same moment, they can sit in that chair.

You are given a **0-indexed** 2D integer array `times` where `times[i] = [arrivali, leavingi]`, indicating the arrival and leaving times of the `ith` friend respectively, and an integer `targetFriend`. All arrival times are **distinct**.

Return _the **chair number** that the friend numbered_ `targetFriend` _will sit on_.

**Example 1:**

```text
Input: times = [[1,4],[2,3],[4,6]], targetFriend = 1
Output: 1
Explanation: 
- Friend 0 arrives at time 1 and sits on chair 0.
- Friend 1 arrives at time 2 and sits on chair 1.
- Friend 1 leaves at time 3 and chair 1 becomes empty.
- Friend 0 leaves at time 4 and chair 0 becomes empty.
- Friend 2 arrives at time 4 and sits on chair 0.
Since friend 1 sat on chair 1, we return 1.
```

**Example 2:**

```text
Input: times = [[3,10],[1,5],[2,6]], targetFriend = 0
Output: 2
Explanation: 
- Friend 1 arrives at time 1 and sits on chair 0.
- Friend 2 arrives at time 2 and sits on chair 1.
- Friend 0 arrives at time 3 and sits on chair 2.
- Friend 1 leaves at time 5 and chair 0 becomes empty.
- Friend 2 leaves at time 6 and chair 1 becomes empty.
- Friend 0 leaves at time 10 and chair 2 becomes empty.
Since friend 0 sat on chair 2, we return 2.
```

**Constraints:**

* `n == times.length`
* `2 <= n <= 10^4`
* `times[i].length == 2`
* `1 <= arrivali < leavingi <= 10^5`
* `0 <= targetFriend <= n - 1`
* Each `arrivali` time is **distinct**.

## Solution

### My Code

```cpp
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int size = times.size();
        vector<vector<int>> entry_time_order;
        vector<vector<int>> exit_time_order;
        vector<int> chair_occupied(size);
        set<int> available_chairs;

        for(int i = 0; i < times.size(); i++)
        {
            entry_time_order.push_back({times[i][0], i});
            exit_time_order.push_back({times[i][1], i});
            available_chairs.insert(i);
        }
        
        sort(entry_time_order.begin(), entry_time_order.end());
        sort(exit_time_order.begin(), exit_time_order.end());

    
        int time = entry_time_order[0][0];
        int entry_index = 0;
        int exit_index = 0;
        while(1) 
        {
            int next_exit = INT_MAX, next_entry = INT_MAX;
            // Check if anyone leaves the party
            for(int i = exit_index; i < size; i++)
            {
                if(exit_time_order[i][0] == time)
                {
                    available_chairs.insert(chair_occupied[exit_time_order[i][1]]);
                    exit_index = i+1;
                }
                else if(exit_time_order[i][0] > time)
                {
                    next_exit = exit_time_order[i][0];
                    break;
                }
            }
            
            //check if anyone entering the party
            for(int i = entry_index; i < size; i++)
            {
                if(entry_time_order[i][0] == time)
                {
                    chair_occupied[entry_time_order[i][1]] = *available_chairs.begin();
                    available_chairs.erase(available_chairs.begin());
                    if(entry_time_order[i][1] == targetFriend)
                        return chair_occupied[entry_time_order[i][1]];
                    entry_index = i+1;
                }
                else if(entry_time_order[i][0] > time)
                {
                    next_entry = entry_time_order[i][0];
                    break;
                }
            }
            
            // Move the next time when either someone leaves/joins the party
            time = min(next_entry, next_exit);
        }
    }
};
```

