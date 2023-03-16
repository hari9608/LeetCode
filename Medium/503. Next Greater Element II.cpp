/*
503. Next Greater Element II
Medium
6.4K
172
company
Amazon
company
Google
company
Adobe

Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.

The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

 

Example 1:

Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2; 
The number 2 can't find next greater number. 
The second 1's next greater number needs to search circularly, which is also 2.

Example 2:

Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]

 

Constraints:

    1 <= nums.length <= 104
    -109 <= nums[i] <= 109

Accepted
294K
Submissions
465.3K
Acceptance Rate
63.2%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (7)
Similar Questions
Next Greater Element I
Easy
Next Greater Element III
Medium
Related Topics
Array
Stack
Monotonic Stack

*/
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        for(int i=2*n-1; i>=0; i--){
            int t = nums[i%n];
            while(!st.empty() && st.top()<=nums[i%n]){
                st.pop();
            }
            if(i<n){
                if(!st.empty())
                    nums[i] = st.top();
                else
                    nums[i] = -1;
            }
            st.push(t);
        }
        return nums;
    }
};
