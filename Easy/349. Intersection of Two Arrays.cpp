/*
349. Intersection of Two Arrays
Easy
4.8K
2.1K
company
Adobe
company
Amazon
company
Google

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.

 

Constraints:

    1 <= nums1.length, nums2.length <= 1000
    0 <= nums1[i], nums2[i] <= 1000

Accepted
861.7K
Submissions
1.2M
Acceptance Rate
71.2%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (36)
Similar Questions
Intersection of Two Arrays II
Easy
Intersection of Three Sorted Arrays
Easy
Find the Difference of Two Arrays
Easy
Count Common Words With One Occurrence
Easy
Choose Numbers From Two Arrays in Range
Hard
Intersection of Multiple Arrays
Easy
Minimum Common Value
Easy
Related Topics
Array
Hash Table
Two Pointers
Binary Search
Sorting
*/
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> map_num1;
        map<int, int> map_num2;
        vector<int> intersection;

        for(auto arr : nums1)    map_num1[arr]++;
        for(auto arr : nums2)    map_num2[arr]++;
        for(auto count : map_num1)  
            if(count.second && map_num2[count.first])       intersection.push_back(count.first);
            
        return intersection;
    }
};