/*
198. House Robber
Medium
17.4K
329
company
Cisco
company
Bloomberg
company
Adobe

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

Example 1:

Input: nums = [1,2,3,1]
Output: 4
Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
Total amount you can rob = 1 + 3 = 4.

Example 2:

Input: nums = [2,7,9,3,1]
Output: 12
Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
Total amount you can rob = 2 + 9 + 1 = 12.

 

Constraints:

    1 <= nums.length <= 100
    0 <= nums[i] <= 400

Accepted
1.6M
Submissions
3.2M
Acceptance Rate
49.4%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (52)
Similar Questions
Maximum Product Subarray
Medium
House Robber II
Medium
Paint House
Medium
Paint Fence
Medium
House Robber III
Medium
Non-negative Integers without Consecutive Ones
Hard
Coin Path
Hard
Delete and Earn
Medium
Solving Questions With Brainpower
Medium
Count Number of Ways to Place Houses
Medium
House Robber IV
Medium
Mice and Cheese
Medium
Related Topics
Array
Dynamic Programming
*/

class Solution {
public:
    int rob(vector<int>& houses) {
        
        int no_houses = houses.size();

        int next_plus_one_house = 0;
        int next_house = houses[no_houses - 1];

        for(int i = no_houses - 2; i >= 0; i--)
        {
            int current_house = max(next_house, next_plus_one_house + houses[i]);

            next_plus_one_house = next_house;
            next_house = current_house;
        }

        return next_house;
    }
};