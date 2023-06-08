/*
2215. Find the Difference of Two Arrays
Easy
1.7K
63
company
Yandex
company
Amazon
company
Adobe

Given two 0-indexed integer arrays nums1 and nums2, return a list answer of size 2 where:

    answer[0] is a list of all distinct integers in nums1 which are not present in nums2.
    answer[1] is a list of all distinct integers in nums2 which are not present in nums1.

Note that the integers in the lists may be returned in any order.

 

Example 1:

Input: nums1 = [1,2,3], nums2 = [2,4,6]
Output: [[1,3],[4,6]]
Explanation:
For nums1, nums1[1] = 2 is present at index 0 of nums2, whereas nums1[0] = 1 and nums1[2] = 3 are not present in nums2. Therefore, answer[0] = [1,3].
For nums2, nums2[0] = 2 is present at index 1 of nums1, whereas nums2[1] = 4 and nums2[2] = 6 are not present in nums2. Therefore, answer[1] = [4,6].

Example 2:

Input: nums1 = [1,2,3,3], nums2 = [1,1,2,2]
Output: [[3],[]]
Explanation:
For nums1, nums1[2] and nums1[3] are not present in nums2. Since nums1[2] == nums1[3], their value is only included once and answer[0] = [3].
Every integer in nums2 is present in nums1. Therefore, answer[1] = [].

 

Constraints:

    1 <= nums1.length, nums2.length <= 1000
    -1000 <= nums1[i], nums2[i] <= 1000

Accepted
145.5K
Submissions
186.4K
Acceptance Rate
78.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (30)
Similar Questions
Intersection of Two Arrays
Easy
Intersection of Two Arrays II
Easy
Intersection of Multiple Arrays
Easy
Related Topics
Array
Hash Table
*/
class Solution {
public:
    vector<int> difference(vector<int>& nums1, vector<int>& nums2)
    {
        set<int> unique_n2(nums2.begin(), nums2.end());
        set<int> unique;

        for(int ind = 0; ind < nums1.size(); ind++)
            if(unique_n2.find(nums1[ind]) == unique_n2.end())
                unique.insert(nums1[ind]);

        return vector<int> (unique.begin(), unique.end());
    }

    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        return {difference(nums1, nums2), difference(nums2, nums1)};
    }
};