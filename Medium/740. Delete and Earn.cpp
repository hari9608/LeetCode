/*
740. Delete and Earn
Medium
6.6K
332
company
Bloomberg
company
Amazon
company
Goldman Sachs

You are given an integer array nums. You want to maximize the number of points you get by performing the following operation any number of times:

    Pick any nums[i] and delete it to earn nums[i] points. Afterwards, you must delete every element equal to nums[i] - 1 and every element equal to nums[i] + 1.

Return the maximum number of points you can earn by applying the above operation some number of times.

 

Example 1:

Input: nums = [3,4,2]
Output: 6
Explanation: You can perform the following operations:
- Delete 4 to earn 4 points. Consequently, 3 is also deleted. nums = [2].
- Delete 2 to earn 2 points. nums = [].
You earn a total of 6 points.

Example 2:

Input: nums = [2,2,3,3,3,4]
Output: 9
Explanation: You can perform the following operations:
- Delete a 3 to earn 3 points. All 2's and 4's are also deleted. nums = [3,3].
- Delete a 3 again to earn 3 points. nums = [3].
- Delete a 3 once more to earn 3 points. nums = [].
You earn a total of 9 points.

 

Constraints:

    1 <= nums.length <= 2 * 104
    1 <= nums[i] <= 104

Accepted
273.2K
Submissions
480.5K
Acceptance Rate
56.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (22)
Similar Questions
House Robber
Medium
Related Topics
Array
Hash Table
Dynamic Programming
*/
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int, int> num_map;
        vector<int> unique;

        for(auto num:nums)      num_map[num] += num;

        for(auto num:num_map)   unique.push_back(num.first);

        int before_two = 0;
        int before_one = num_map[unique[0]];

        for(int i=1; i<unique.size(); i++)
        {
            int current_ele = unique[i];
            int temp = before_one;

            if(current_ele == unique[i-1] + 1)
                before_one = max(before_one, before_two + num_map[current_ele]);

            else
                before_one += num_map[current_ele];
            
            before_two = temp;
        }

        return before_one;
    }
};