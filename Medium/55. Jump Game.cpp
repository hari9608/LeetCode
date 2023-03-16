/*
55. Jump Game
Medium
15.6K
800
company
Amazon
company
Microsoft
company
Bloomberg

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

 

Constraints:

    1 <= nums.length <= 104
    0 <= nums[i] <= 105


Similar Questions
Jump Game II 		Medium
Jump Game III 		Medium
Jump Game VIII		Medium
Jump Game VIII 		Medium

Related Topics
		Array
		Dynamic Programming
		Greedy
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int nums_len = nums.size();
        int curr = 0;
        for (int next = 0; curr < nums_len && curr <= next; ++curr)
            next = max(curr + nums[curr], next);
        return curr == nums_len;

       /* int nums_len = nums.size();
        int stand = 0;
        int next = 0;

        if(nums_len == 1) return true;

        while(stand != nums_len-1)
        {
            if(stand+nums[stand] >= nums_len-1)  return true;
            if(nums[stand] == 0) return false;

            priority_queue<pair<int,int>> pr_que;
            next = stand + 1;
            
            for(int i=next; i<next + nums[stand] && i<nums_len; i++)
                pr_que.push({nums[i],i});

            stand = pr_que.top().second;
            while(stand + nums[stand] < nums_len && nums[stand + nums[stand]] == 0 && pr_que.size()>1)     {        
                pr_que.pop();
            stand = pr_que.top().second;
            }
        }

        return true;*/
    }
};