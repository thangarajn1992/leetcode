# Leetcode 210 Course Schedule II

## Problem Statement

[https://leetcode.com/problems/course-schedule-ii/](https://leetcode.com/problems/course-schedule-ii/)

There are a total of `numCourses` courses you have to take, labeled from `0` to `numCourses - 1`. You are given an array `prerequisites` where `prerequisites[i] = [ai, bi]` indicates that you **must** take course `bi` first if you want to take course `ai`.

* For example, the pair `[0, 1]`, indicates that to take course `0` you have to first take course `1`.

Return _the ordering of courses you should take to finish all courses_. If there are many valid answers, return **any** of them. If it is impossible to finish all courses, return **an empty array**.

**Example 1:**

```text
Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: 
There are a total of 2 courses to take. To take course 1 you should have finished course 0. 
So the correct course order is [0,1].
```

**Example 2:**

```text
Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: 
There are a total of 4 courses to take. To take course 3 you should have finished both 
courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
```

**Example 3:**

```text
Input: numCourses = 1, prerequisites = []
Output: [0]
```

**Constraints:**

* `1 <= numCourses <= 2000`
* `0 <= prerequisites.length <= numCourses * (numCourses - 1)`
* `prerequisites[i].length == 2`
* `0 <= ai, bi < numCourses`
* `ai != bi`
* All the pairs `[ai, bi]` are **distinct**.

## Solution

### My Approach

```cpp
class Solution {
public:
    int V;
    vector<int> *dependents;  // courses that depends on this course to be completed
    vector<int> depended_on; // No. of courses this course depends on
    vector<int> course_completion_order; // Order in which all courses can be completed
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
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
        return (courses_completed == numCourses)? course_completion_order : vector<int>({});        
    }
    
    void DFS(int course, vector<bool>&visited, int &courses_completed)
    {   
        
        visited[course] = true;
        courses_completed++;
        course_completion_order.push_back(course);
        
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

