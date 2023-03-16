/*
2244. Minimum Rounds to Complete All Tasks
Medium
2.5K
70
company
Amazon

You are given a 0-indexed integer array tasks, where tasks[i] represents the difficulty level of a task. In each round, you can complete either 2 or 3 tasks of the same difficulty level.

Return the minimum rounds required to complete all the tasks, or -1 if it is not possible to complete all the tasks.

 

Example 1:

Input: tasks = [2,2,3,3,2,4,4,4,4,4]
Output: 4
Explanation: To complete all the tasks, a possible plan is:
- In the first round, you complete 3 tasks of difficulty level 2. 
- In the second round, you complete 2 tasks of difficulty level 3. 
- In the third round, you complete 3 tasks of difficulty level 4. 
- In the fourth round, you complete 2 tasks of difficulty level 4.  
It can be shown that all the tasks cannot be completed in fewer than 4 rounds, so the answer is 4.

Example 2:

Input: tasks = [2,3,3]
Output: -1
Explanation: There is only 1 task of difficulty level 2, but in each round, you can only complete either 2 or 3 tasks of the same difficulty level. Hence, you cannot complete all the tasks, and the answer is -1.

 

Constraints:

    1 <= tasks.length <= 105
    1 <= tasks[i] <= 109

Accepted
130.2K
Submissions
206.8K
Acceptance Rate
62.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (76)
Similar Questions
Climbing Stairs
Easy
Odd String Difference
Easy
Related Topics
Array
Hash Table
Greedy
Counting

*/

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int, int> rounds;
        int minimum_rounds = 0;

        for(int task : tasks) rounds[task]++;
        
        for(auto task : rounds)
            if(task.second == 1)    return -1;
            else minimum_rounds += task.second % 3 ? (task.second / 3) + 1 : task.second / 3;

        return minimum_rounds;
    }
};