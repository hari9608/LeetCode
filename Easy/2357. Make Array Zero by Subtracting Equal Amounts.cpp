/*
2357. Make Array Zero by Subtracting Equal Amounts
Easy
886
35
company
Amazon

You are given a non-negative integer array nums. In one operation, you must:

    Choose a positive integer x such that x is less than or equal to the smallest non-zero element in nums.
    Subtract x from every positive element in nums.

Return the minimum number of operations to make every element in nums equal to 0.

 

Example 1:

Input: nums = [1,5,0,3,5]
Output: 3
Explanation:
In the first operation, choose x = 1. Now, nums = [0,4,0,2,4].
In the second operation, choose x = 2. Now, nums = [0,2,0,0,2].
In the third operation, choose x = 2. Now, nums = [0,0,0,0,0].

Example 2:

Input: nums = [0]
Output: 0
Explanation: Each element in nums is already 0 so no operations are needed.

 

Constraints:

    1 <= nums.length <= 100
    0 <= nums[i] <= 100

Accepted
69.6K
Submissions
96.3K
Acceptance Rate
72.3%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (7)
Similar Questions
Contains Duplicate
Easy
Related Topics
Array
Hash Table
Greedy
Sorting
Heap (Priority Queue)
Simulation
*/
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        /*
        unordered_set<int> unique;
        for(auto v: nums)   if(v)      unique.insert(v);  
        return unique.size();
        */
        priority_queue<int, vector<int>, greater<int>> min_que;


        for(auto v: nums)   min_que.push(v);
//  

        int k = 0;
        int res = -1;

        while(min_que.size() != 0)
        {
            while(!min_que.empty() && min_que.top()-k==0)     min_que.pop();
            k = min_que.top();
            res++;
        }
        return res;
        
    }
};