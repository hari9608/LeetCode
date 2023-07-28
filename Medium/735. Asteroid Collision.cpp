/*
735. Asteroid Collision
Medium
6.7K
683
company
Amazon
company
Salesforce
company
DoorDash

We are given an array asteroids of integers representing asteroids in a row.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

 

Example 1:

Input: asteroids = [5,10,-5]
Output: [5,10]
Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.

Example 2:

Input: asteroids = [8,-8]
Output: []
Explanation: The 8 and -8 collide exploding each other.

Example 3:

Input: asteroids = [10,2,-5]
Output: [10]
Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.

 

Constraints:

    2 <= asteroids.length <= 104
    -1000 <= asteroids[i] <= 1000
    asteroids[i] != 0

Accepted
361.9K
Submissions
790.5K
Acceptance Rate
45.8%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (97)
Similar Questions
Can Place Flowers
Easy
Destroying Asteroids
Medium
Count Collisions on a Road
Medium
Robot Collisions
Hard
Related Topics
Array
Stack
Simulation
*/
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        
        for (int asteroid : asteroids) 
        {
            int flag = 1;
        
            while (!st.empty() && (st.top() > 0 && asteroid < 0)) 
            {
                if (abs(st.top()) < abs(asteroid)) 
                {
                    st.pop();
                    continue;
                }
                else if (abs(st.top()) == abs(asteroid)) 
                    st.pop();

                flag = 0;
                break;
            }
            
            if (flag) 
                st.push(asteroid);
        }
        
        vector<int> remaining_asteroids (st.size());
        
        for (int i = remaining_asteroids.size() - 1; i >= 0; i--)
            remaining_asteroids[i] = st.top(), st.pop();
        
        return remaining_asteroids;
    }
};