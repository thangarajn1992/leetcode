# Leetcode 207 Course Schedule

## Problem Statement

[https://leetcode.com/problems/course-schedule/](https://leetcode.com/problems/course-schedule/)

There are a total of `numCourses` courses you have to take, labeled from `0` to `numCourses - 1`. You are given an array `prerequisites` where `prerequisites[i] = [ai, bi]` indicates that you **must** take course `bi` first if you want to take course `ai`.

* For example, the pair `[0, 1]`, indicates that to take course `0` you have to first take course `1`.

Return `true` if you can finish all courses. Otherwise, return `false`.

**Example 1:**

```text
Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: 
There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
```

**Example 2:**

```text
Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: 
There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should 
also have finished course 1. So it is impossible.
```

**Constraints:**

* `1 <= numCourses <= 10^5`
* `0 <= prerequisites.length <= 5000`
* `prerequisites[i].length == 2`
* `0 <= ai, bi < numCourses`
* All the pairs prerequisites\[i\] are **unique**.

## Solution

### My Approach

```cpp
class Solution {
public:
    int V;
    vector<int> *dependents;  // courses that depends on this course to be completed
    vector<int> depended_on; // No. of courses this course depends on
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        V = numCourses;
        dependents = new vector<int>[numCourses];
        depended_on.resize(numCourses,0);
        
        for(int i = 0; i < prerequisites.size(); i++)
        {
            dependents[prerequisites[i][1]].push_back(prerequisites[i][0]);
            depended_on[prerequisites[i][0]]++;
        }
        

        int courses_completed = 0;
        vector<bool> visited(numCourses, false);
        
        // To avoid infinite loop when we can't complete any more course
        bool valid_loop = true; 
        
        // Find a nodes with no pre-requisite and complete as many courses as possible
        while(courses_completed < numCourses && valid_loop)
        {
            int old_courses_completed = courses_completed;
            
            for(int course = 0; course < numCourses; course++)
                if(depended_on[course] == 0 && visited[course] == false)
                    DFS(course, visited, courses_completed);

            valid_loop = (old_courses_completed != courses_completed);
        }
        return courses_completed == numCourses;
    }

    void DFS(int course, vector<bool>&visited, int &courses_completed)
    {   
        visited[course] = true;
        courses_completed++;
        
        // Reduce dependency count for all dependents of this course
        for(int dependent = 0; dependent < dependents[course].size(); dependent++)
        {
            if(visited[dependents[course][dependent]] == false)
                depended_on[dependents[course][dependent]]--;
        }
        
        // If any dependent course's dependency cnt bec
        for(int dependent = 0; dependent < dependents[course].size(); dependent++)
        {
            if(depended_on[dependents[course][dependent]] == 0 && 
               visited[dependents[course][dependent]] == false)
                
                DFS(dependents[course][dependent], visited, courses_completed);
        }   
    }
};
```

