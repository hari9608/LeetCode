/*
1313. Decompress Run-Length Encoded List
Easy
1.1K
1.3K
company
Apple
company
Amazon
company
Google

We are given a list nums of integers representing a list compressed with run-length encoding.

Consider each adjacent pair of elements [freq, val] = [nums[2*i], nums[2*i+1]] (with i >= 0).  For each such pair, there are freq elements with value val concatenated in a sublist. Concatenate all the sublists from left to right to generate the decompressed list.

Return the decompressed list.

 

Example 1:

Input: nums = [1,2,3,4]
Output: [2,4,4,4]
Explanation: The first pair [1,2] means we have freq = 1 and val = 2 so we generate the array [2].
The second pair [3,4] means we have freq = 3 and val = 4 so we generate [4,4,4].
At the end the concatenation [2] + [4,4,4] is [2,4,4,4].

Example 2:

Input: nums = [1,1,2,3]
Output: [1,3,3]

 

Constraints:

    2 <= nums.length <= 100
    nums.length % 2 == 0
    1 <= nums[i] <= 100

Accepted
229.5K
Submissions
267.9K
Acceptance Rate
85.7%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (19)
Similar Questions
String Compression
Medium
Related Topics
Array
*/
class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> decompressed_list;
        for(int i=0; i<nums.size(); i+=2)
            while(nums[i]--)
                decompressed_list.push_back(nums[i+1]);
        return decompressed_list;
    }
};