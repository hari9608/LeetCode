/*
350. Intersection of Two Arrays II
Easy
6.5K
875
company
Yandex
company
Amazon
company
Adobe

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

 

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]

Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.

 

Constraints:

    1 <= nums1.length, nums2.length <= 1000
    0 <= nums1[i], nums2[i] <= 1000

 

Follow up:

    What if the given array is already sorted? How would you optimize your algorithm?
    What if nums1's size is small compared to nums2's size? Which algorithm is better?
    What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

Accepted
1.1M
Submissions
1.9M
Acceptance Rate
56.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (46)
Similar Questions
Intersection of Two Arrays
Easy
Find Common Characters
Easy
Find the Difference of Two Arrays
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
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        int i=0;
        int j=0;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        while(i<nums1.size() && j<nums2.size())
            if(nums1[i]==nums2[j])
            {
                arr.push_back(nums1[i]);
                i++; j++;
            }
            else if(nums1[i] < nums2[j])
                i++;
            else
                j++;
            
        return arr;
    }
};