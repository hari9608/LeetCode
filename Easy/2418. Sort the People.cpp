/*
2418. Sort the People
Easy
919
15
company
Infosys

You are given an array of strings names, and an array heights that consists of distinct positive integers. Both arrays are of length n.

For each index i, names[i] and heights[i] denote the name and height of the ith person.

Return names sorted in descending order by the people's heights.

 

Example 1:

Input: names = ["Mary","John","Emma"], heights = [180,165,170]
Output: ["Mary","Emma","John"]
Explanation: Mary is the tallest, followed by Emma and John.

Example 2:

Input: names = ["Alice","Bob","Bob"], heights = [155,185,150]
Output: ["Bob","Alice","Bob"]
Explanation: The first Bob is the tallest, followed by Alice and the second Bob.

 

Constraints:

    n == names.length == heights.length
    1 <= n <= 103
    1 <= names[i].length <= 20
    1 <= heights[i] <= 105
    names[i] consists of lower and upper case English letters.
    All the values of heights are distinct.

Accepted
78.8K
Submissions
98K
Acceptance Rate
80.4%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (15)
Similar Questions
Sort Array by Increasing Frequency
Easy
Sort the Students by Their Kth Score
Medium
Related Topics
Array
Hash Table
String
Sorting
*/
class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string> order_height;
        vector<string> sort_people;

        for(int i=0; i<names.size(); i++)
            order_height[heights[i]] = names[i];

        for(auto itr=order_height.rbegin(); itr!=order_height.rend(); itr++)
            sort_people.push_back(itr->second);

        return sort_people;
    }
};

/*

        for(int i=0; i<names.size(); i++)
            order_height[-heights[i]] = names[i];

        for(auto itr : order_height)
            sort_people.push_back(itr.second);

*/