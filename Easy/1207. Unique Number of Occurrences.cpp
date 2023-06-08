/*
1207. Unique Number of Occurrences
Easy
3.6K
82
company
Amazon
company
Apple
company
Adobe

Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

 

Example 1:

Input: arr = [1,2,2,1,1,3]
Output: true
Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.

Example 2:

Input: arr = [1,2]
Output: false

Example 3:

Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
Output: true

 

Constraints:

    1 <= arr.length <= 1000
    -1000 <= arr[i] <= 1000

Accepted
282.3K
Submissions
383.5K
Acceptance Rate
73.6%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (63)
Related Topics
Array
Hash Table
*/
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> unique;
        for(auto a : arr)   unique[a]++;
        set<int> fre;
        for(auto un : unique)   fre.insert(un.second);
        return fre.size() == unique.size();
    }
};