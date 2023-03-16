/*
347. Top K Frequent Elements
Medium
12.9K
476
company
Amazon
company
Facebook
company
Google

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:

Input: nums = [1], k = 1
Output: [1]

 

Constraints:

    1 <= nums.length <= 105
    -104 <= nums[i] <= 104
    k is in the range [1, the number of unique elements in the array].
    It is guaranteed that the answer is unique.

 

Follow up: Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
Accepted
1.3M
Submissions
2.1M
Acceptance Rate
64.3%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (48)
Similar Questions
Word Frequency
Medium
Kth Largest Element in an Array
Medium
Sort Characters By Frequency
Medium
Split Array into Consecutive Subsequences
Medium
Top K Frequent Words
Medium
K Closest Points to Origin
Medium
Sort Features by Popularity
Medium
Sender With Largest Word Count
Medium
Most Frequent Even Element
Easy
Related Topics
Array
Hash Table
Divide and Conquer
Sorting
Heap (Priority Queue)
Bucket Sort
Counting
Quickselect

*/
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> kfre;
        map<int, int> nums_fre;
        priority_queue<pair<int, int>> pr_que;
        
        for(int v:nums)             nums_fre[v]++;
        for(auto num: nums_fre)     pr_que.push({num.second, num.first});
        
        while(k!=0 && pr_que.size() > 0)
        {
            kfre.push_back(pr_que.top().second);
            pr_que.pop();
            k--;
        }
        
        return kfre;
    }
};