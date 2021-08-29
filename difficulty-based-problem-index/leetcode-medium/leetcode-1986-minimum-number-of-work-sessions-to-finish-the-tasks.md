# Leetcode 1986 Minimum Number of Work Sessions to Finish the Tasks

## Problem Statement

[https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/](https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/)

There are `n` tasks assigned to you. The task times are represented as an integer array `tasks` of length `n`, where the `ith` task takes `tasks[i]` hours to finish. A **work session** is when you work for **at most** `sessionTime` consecutive hours and then take a break.

You should finish the given tasks in a way that satisfies the following conditions:

* If you start a task in a work session, you must complete it in the **same** work session.
* You can start a new task **immediately** after finishing the previous one.
* You may complete the tasks in **any order**.

Given `tasks` and `sessionTime`, return _the **minimum** number of **work sessions** needed to finish all the tasks following the conditions above._

The tests are generated such that `sessionTime` is **greater** than or **equal** to the **maximum** element in `tasks[i]`.

**Example 1:**

```text
Input: tasks = [1,2,3], sessionTime = 3
Output: 2
Explanation: You can finish the tasks in two work sessions.
- First work session: finish the first and the second tasks in 1 + 2 = 3 hours.
- Second work session: finish the third task in 3 hours.
```

**Example 2:**

```text
Input: tasks = [3,1,3,1,1], sessionTime = 8
Output: 2
Explanation: You can finish the tasks in two work sessions.
- First work session: finish all the tasks except the last one in 3 + 1 + 3 + 1 = 8 hours.
- Second work session: finish the last task in 1 hour.
```

**Example 3:**

```text
Input: tasks = [1,2,3,4,5], sessionTime = 15
Output: 1
Explanation: You can finish all the tasks in one work session.
```

**Constraints:**

* `n == tasks.length`
* `1 <= n <= 14`
* `1 <= tasks[i] <= 10`
* `max(tasks[i]) <= sessionTime <= 15`

## Solution

### Backtracking Approach

For each task, we have two option

1. To accomadate this task in one of the earlier sessions, given that earlier session time + cur\_task\_time &lt;= max session time.
2. To create a new session and allocate this task to that session.

We optimize the backtrack by breaking the recursion if our current session count exceeds that already calculated minimum session count.

```cpp
class Solution {
public:
    int minSession = INT_MAX;
    vector<int> sessions;
    int minSessions(vector<int>& tasks, int sessionTime) 
    {
        solve(0 ,tasks, sessionTime);
        return minSession;
    }
    
    void solve(int index, vector<int>& tasks, int target)
    {
        // All tasks are scheduled, if sessions is new minimum, update it.
        if(index >= tasks.size())
        {
            if(minSession > sessions.size())
                minSession = sessions.size();
            return ;
        }
        
        // if current session count is already greater than our min value, don't proceed 
        if(sessions.size() > minSession)
            return;  
		
        //Case 1: Try to fit this task in one of the possible previous sessions.
        for(int sessionNum = 0; sessionNum < sessions.size(); sessionNum++)
        {
            if(sessions[sessionNum] + tasks[index] <= target)
            {
                sessions[sessionNum] += tasks[index];
                solve(index+1, tasks, target);
                sessions[sessionNum] -= tasks[index];
            }
        }
        
        //Case 2: Put task as part of new session
        sessions.push_back(tasks[index]);
        solve(index+1, tasks, target);
        sessions.pop_back();        
    }
};
```

