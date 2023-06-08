/*
2389. Longest Subsequence With Limited Sum
Easy
1.6K
140

You are given an integer array nums of length n, and an integer array queries of length m.

Return an array answer of length m where answer[i] is the maximum size of a subsequence that you can take from nums such that the sum of its elements is less than or equal to queries[i].

A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

 

Example 1:

Input: nums = [4,5,2,1], queries = [3,10,21]
Output: [2,3,4]
Explanation: We answer the queries as follows:
- The subsequence [2,1] has a sum less than or equal to 3. It can be proven that 2 is the maximum size of such a subsequence, so answer[0] = 2.
- The subsequence [4,5,1] has a sum less than or equal to 10. It can be proven that 3 is the maximum size of such a subsequence, so answer[1] = 3.
- The subsequence [4,5,2,1] has a sum less than or equal to 21. It can be proven that 4 is the maximum size of such a subsequence, so answer[2] = 4.

Example 2:

Input: nums = [2,3,4,5], queries = [1]
Output: [0]
Explanation: The empty subsequence is the only subsequence that has a sum less than or equal to 1, so answer[0] = 0.

 

Constraints:

    n == nums.length
    m == queries.length
    1 <= n, m <= 1000
    1 <= nums[i], queries[i] <= 106

Accepted
83.8K
Submissions
116.2K
Acceptance Rate
72.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (60)
Similar Questions
How Many Numbers Are Smaller Than the Current Number
Easy
Successful Pairs of Spells and Potions
Medium
Related Topics
Array
Binary Search
Greedy
Sorting
Prefix Sum
*/
class Solution {
public:
    int find_answer(int query, vector<int>& nums, int num_len)
    {
        int left = 0;
        int right = num_len - 1;
        
        if(query < nums[0])
            return 0;
        
        if(query >= nums[right])
            return num_len;

        while(left <= right)
        {
            int mid = (right + left) / 2;

            if(nums[mid] <= query && nums[mid + 1] > query)
                return mid + 1;
            else if(nums[mid] < query)
                left = mid + 1;
            else 
                right = mid - 1;
        }

        return -1;
    } 

    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int queries_len = queries.size();
        int nums_len = nums.size();

        vector<int> answer_queries(queries_len);

        sort(nums.begin(), nums.end());

        for(int i = 1; i < nums.size(); i++)
            nums[i] += nums[i - 1];

        for(int i = 0; i < queries_len; i++)
            answer_queries[i] = find_answer(queries[i], nums, nums_len);

        return answer_queries;
    }
};