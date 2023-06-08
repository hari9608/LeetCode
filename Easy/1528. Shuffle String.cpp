/*
1528. Shuffle String
Easy
2.3K
411
company
Google
company
Facebook
company
Apple

You are given a string s and an integer array indices of the same length. The string s will be shuffled such that the character at the ith position moves to indices[i] in the shuffled string.

Return the shuffled string.

 

Example 1:

Input: s = "codeleet", indices = [4,5,6,7,0,2,1,3]
Output: "leetcode"
Explanation: As shown, "codeleet" becomes "leetcode" after shuffling.

Example 2:

Input: s = "abc", indices = [0,1,2]
Output: "abc"
Explanation: After shuffling, each character remains in its position.

 

Constraints:

    s.length == indices.length == n
    1 <= n <= 100
    s consists of only lowercase English letters.
    0 <= indices[i] < n
    All values of indices are unique.

Accepted
300.9K
Submissions
354.3K
Acceptance Rate
84.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (60)
Related Topics
Array
String
*/
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int indicesSize = s.size();
        char ans[indicesSize+1];

        for(int i=0; i<indicesSize; i++)
            ans[indices[i]] = s[i];

        string str = "";
        for(int i=0; i<indicesSize; i++)
            str += ans[i];
        return str;
    }
};