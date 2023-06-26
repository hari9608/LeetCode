/*
582. Kill Process
Medium
1.1K
21
company
Amazon
company
Microsoft
company
Bloomberg

You have n processes forming a rooted tree structure. You are given two integer arrays pid and ppid, where pid[i] is the ID of the ith process and ppid[i] is the ID of the ith process's parent process.

Each process has only one parent process but may have multiple children processes. Only one process has ppid[i] = 0, which means this process has no parent process (the root of the tree).

When a process is killed, all of its children processes will also be killed.

Given an integer kill representing the ID of a process you want to kill, return a list of the IDs of the processes that will be killed. You may return the answer in any order.

 

Example 1:

Input: pid = [1,3,10,5], ppid = [3,0,5,3], kill = 5
Output: [5,10]
Explanation: The processes colored in red are the processes that should be killed.

Example 2:

Input: pid = [1], ppid = [0], kill = 1
Output: [1]

 

Constraints:

    n == pid.length
    n == ppid.length
    1 <= n <= 5 * 104
    1 <= pid[i] <= 5 * 104
    0 <= ppid[i] <= 5 * 104
    Only one process has no parent.
    All the values of pid are unique.
    kill is guaranteed to be in pid.

Accepted
79.6K
Submissions
115.7K
Acceptance Rate
68.8%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (0)
Related Topics
Array
Hash Table
Tree
Depth-First Search
Breadth-First Search
*/
class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        map<int, vector<int>> parent_child;
        vector<int> kill_process; 

        for(int id = 0; id < pid.size(); id++)
            parent_child[ppid[id]].push_back(pid[id]);

        kill_process.push_back(kill);
        int curr_kill = 0;
        // queue<int> kill_child;
        // kill_child.push(kill);

        while(curr_kill != kill_process.size()) //!kill_child.empty())
        {
            int kill_next = kill_process[curr_kill]; // kill_child.front();
            // cout << "kill -> " << curr_kill << " kill_process size -> " << kill_process.size() << endl;
            // kill_child.pop();
            
            for(int child : parent_child[kill_next])
                kill_process.push_back(child);
                // kill_child.push(child);

            curr_kill++;
        }

        return kill_process;
    }
};