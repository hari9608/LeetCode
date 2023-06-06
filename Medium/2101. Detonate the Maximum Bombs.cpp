/*
2101. Detonate the Maximum Bombs
Medium
2.4K
124
company
Google
Qualtrics

You are given a list of bombs. The range of a bomb is defined as the area where its effect can be felt. This area is in the shape of a circle with the center as the location of the bomb.

The bombs are represented by a 0-indexed 2D integer array bombs where bombs[i] = [xi, yi, ri]. xi and yi denote the X-coordinate and Y-coordinate of the location of the ith bomb, whereas ri denotes the radius of its range.

You may choose to detonate a single bomb. When a bomb is detonated, it will detonate all bombs that lie in its range. These bombs will further detonate the bombs that lie in their ranges.

Given the list of bombs, return the maximum number of bombs that can be detonated if you are allowed to detonate only one bomb.

 

Example 1:

Input: bombs = [[2,1,3],[6,1,4]]
Output: 2
Explanation:
The above figure shows the positions and ranges of the 2 bombs.
If we detonate the left bomb, the right bomb will not be affected.
But if we detonate the right bomb, both bombs will be detonated.
So the maximum bombs that can be detonated is max(1, 2) = 2.

Example 2:

Input: bombs = [[1,1,5],[10,10,5]]
Output: 1
Explanation:
Detonating either bomb will not detonate the other bomb, so the maximum number of bombs that can be detonated is 1.

Example 3:

Input: bombs = [[1,2,3],[2,3,1],[3,4,2],[4,5,3],[5,6,4]]
Output: 5
Explanation:
The best bomb to detonate is bomb 0 because:
- Bomb 0 detonates bombs 1 and 2. The red circle denotes the range of bomb 0.
- Bomb 2 detonates bomb 3. The blue circle denotes the range of bomb 2.
- Bomb 3 detonates bomb 4. The green circle denotes the range of bomb 3.
Thus all 5 bombs are detonated.

 

Constraints:

    1 <= bombs.length <= 100
    bombs[i].length == 3
    1 <= xi, yi, ri <= 105

Accepted
80.7K
Submissions
161.5K
Acceptance Rate
50.0%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (68)
Similar Questions
Minesweeper
Medium
Number of Provinces
Medium
Max Area of Island
Medium
Rotting Oranges
Medium
Related Topics
Array
Math
Depth-First Search
Breadth-First Search
Graph
Geometry
*/
class Solution {
public:
    int bfs(int i, map<int, vector<int>>& graph) {
        queue<int> queue;
        set<int> visited;

        queue.push(i);
        visited.insert(i);

        while (!queue.empty()) 
        {
            int cur = queue.front();
            queue.pop();

            for (int neib : graph[cur]) 
                if (!visited.count(neib)) 
                {
                    visited.insert(neib);
                    queue.push(neib);
                }
        }

        return visited.size();
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        map<int, vector<int>> graph;
        int n = bombs.size();
        int answer = 0;
        
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
            {
                int xi = bombs[i][0];
                int yi = bombs[i][1];
                int ri = bombs[i][2];
                int xj = bombs[j][0];
                int yj = bombs[j][1];
                
                if ((long)ri * ri >= (long)(xi - xj) * (xi - xj) + (long)(yi - yj) * (yi - yj)) 
                    graph[i].push_back(j); 
            }
        
        for (int i = 0; i < n; i++) 
            answer = max(answer, bfs(i, graph));
        
        return answer;
    }
};