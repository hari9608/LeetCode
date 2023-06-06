/*
946. Validate Stack Sequences
Medium
5.5K
107
company
Amazon
company
Yahoo
company
Google

Given two integer arrays pushed and popped each with distinct values, return true if this could have been the result of a sequence of push and pop operations on an initially empty stack, or false otherwise.

 

Example 1:

Input: pushed = [1,2,3,4,5], popped = [4,5,3,2,1]
Output: true
Explanation: We might do the following sequence:
push(1), push(2), push(3), push(4),
pop() -> 4,
push(5),
pop() -> 5, pop() -> 3, pop() -> 2, pop() -> 1

Example 2:

Input: pushed = [1,2,3,4,5], popped = [4,3,5,1,2]
Output: false
Explanation: 1 cannot be popped before 2.

 

Constraints:

    1 <= pushed.length <= 1000
    0 <= pushed[i] <= 1000
    All the elements of pushed are unique.
    popped.length == pushed.length
    popped is a permutation of pushed.

Accepted
271K
Submissions
390.3K
Acceptance Rate
69.4%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (33)
Related Topics
Array
Stack
Simulation
*/
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int N = pushed.size();
        stack<int> stack;
        int popped_ind = 0;
        
        for (int x: pushed) 
        {
            stack.push(x);
            while (!stack.empty() && popped_ind < N && stack.top() == popped[popped_ind]) 
            {
                stack.pop();
                popped_ind++;
            }
        }

        return popped_ind == N;
    }
};