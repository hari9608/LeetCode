/*
2475. Number of Unequal Triplets in Array
Easy
295
25
company
PayTM

You are given a 0-indexed array of positive integers nums. Find the number of triplets (i, j, k) that meet the following conditions:

    0 <= i < j < k < nums.length
    nums[i], nums[j], and nums[k] are pairwise distinct.
        In other words, nums[i] != nums[j], nums[i] != nums[k], and nums[j] != nums[k].

Return the number of triplets that meet the conditions.

 

Example 1:

Input: nums = [4,4,2,4,3]
Output: 3
Explanation: The following triplets meet the conditions:
- (0, 2, 4) because 4 != 2 != 3
- (1, 2, 4) because 4 != 2 != 3
- (2, 3, 4) because 2 != 4 != 3
Since there are 3 triplets, we return 3.
Note that (2, 0, 4) is not a valid triplet because 2 > 0.

Example 2:

Input: nums = [1,1,1,1,1]
Output: 0
Explanation: No triplets meet the conditions so we return 0.

 

Constraints:

    3 <= nums.length <= 100
    1 <= nums[i] <= 1000

Accepted
28.3K
Submissions
40K
Acceptance Rate
70.8%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (7)
Similar Questions
Count Good Triplets
Easy
Count Square Sum Triples
Easy
Number of Arithmetic Triplets
Easy
Related Topics
Array
Hash Table
*/
class Solution {
public:
    int unequalTriplets(vector<int>& nums) {
        map<int, int> fre_nums;
        int left = 0;
        int right = nums.size();
        int result = 0;

        for(auto num : nums)    fre_nums[num]++;

        for(auto num : fre_nums)
        {
            right -= num.second;
            result += left * num.second * right;
            left += num.second;
        }

        return result;
    }
};