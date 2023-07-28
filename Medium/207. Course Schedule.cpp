/*
207. Course Schedule
Medium
14.3K
566
company
Amazon
company
Google
company
Apple

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

    For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.

Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

 

Constraints:

    1 <= numCourses <= 2000
    0 <= prerequisites.length <= 5000
    prerequisites[i].length == 2
    0 <= ai, bi < numCourses
    All the pairs prerequisites[i] are unique.

Accepted
1.2M
Submissions
2.7M
Acceptance Rate
45.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (94)
Similar Questions
Course Schedule II
Medium
Graph Valid Tree
Medium
Minimum Height Trees
Medium
Course Schedule III
Hard
Build a Matrix With Conditions
Hard
Related Topics
Depth-First Search
Breadth-First Search
Graph
Topological Sort
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> courses(numCourses);
        vector<int> in_deg(numCourses);
        int can_finish = 0;
        queue<int> que;

        for(auto prerequisite : prerequisites)
        {
            courses[prerequisite[1]].push_back(prerequisite[0]);
            in_deg[prerequisite[0]]++;
        }

        for(int ind = 0; ind < numCourses; ind++)
            if(!in_deg[ind])
                que.push(ind);

        while(!que.empty())
        {
            int node = que.front();
            que.pop();
            can_finish++;

            for(int course : courses[node])
            {
                in_deg[course]--;
                if(!in_deg[course])
                    que.push(course);
            }
        }

        return can_finish == numCourses;
    }
};