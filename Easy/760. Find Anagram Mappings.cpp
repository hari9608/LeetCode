/*
760. Find Anagram Mappings
Easy
578
220
company
Google

You are given two integer arrays nums1 and nums2 where nums2 is an anagram of nums1. Both arrays may contain duplicates.

Return an index mapping array mapping from nums1 to nums2 where mapping[i] = j means the ith element in nums1 appears in nums2 at index j. If there are multiple answers, return any of them.

An array a is an anagram of an array b means b is made by randomizing the order of the elements in a.

 

Example 1:

Input: nums1 = [12,28,46,32,50], nums2 = [50,12,32,46,28]
Output: [1,4,3,2,0]
Explanation: As mapping[0] = 1 because the 0th element of nums1 appears at nums2[1], and mapping[1] = 4 because the 1st element of nums1 appears at nums2[4], and so on.

Example 2:

Input: nums1 = [84,46], nums2 = [84,46]
Output: [0,1]

 

Constraints:

    1 <= nums1.length <= 100
    nums2.length == nums1.length
    0 <= nums1[i], nums2[i] <= 105
    nums2 is an anagram of nums1.

Accepted
93.7K
Submissions
112.5K
Acceptance Rate
83.4%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (1)
Related Topics
Array
Hash Table
*/
class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        map<int, queue<int>> map_que;
        vector<int> anagram_mappings;
        int nums_len = nums2.size();

        for(int i=0; i<nums_len; i++)   
            map_que[nums2[i]].push(i);
            
        for(int i=0; i<nums_len; i++)   
        {
            anagram_mappings.push_back(map_que[nums1[i]].front());
            map_que[nums1[i]].pop();
        }

        return anagram_mappings;
    }
};