/*
422. Valid Word Square
Easy
390
249
company
Google

Given an array of strings words, return true if it forms a valid word square.

A sequence of strings forms a valid word square if the kth row and column read the same string, where 0 <= k < max(numRows, numColumns).

 

Example 1:

Input: words = ["abcd","bnrt","crmy","dtye"]
Output: true
Explanation:
The 1st row and 1st column both read "abcd".
The 2nd row and 2nd column both read "bnrt".
The 3rd row and 3rd column both read "crmy".
The 4th row and 4th column both read "dtye".
Therefore, it is a valid word square.

Example 2:

Input: words = ["abcd","bnrt","crm","dt"]
Output: true
Explanation:
The 1st row and 1st column both read "abcd".
The 2nd row and 2nd column both read "bnrt".
The 3rd row and 3rd column both read "crm".
The 4th row and 4th column both read "dt".
Therefore, it is a valid word square.

Example 3:

Input: words = ["ball","area","read","lady"]
Output: false
Explanation:
The 3rd row reads "read" while the 3rd column reads "lead".
Therefore, it is NOT a valid word square.

 

Constraints:

    1 <= words.length <= 500
    1 <= words[i].length <= 500
    words[i] consists of only lowercase English letters.

Accepted
50.5K
Submissions
125.9K
Acceptance Rate
40.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (4)
Similar Questions
Word Squares
Hard
Toeplitz Matrix
Easy
Related Topics
Array
Matrix
*/
class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        for(int row=0; row<words.size(); row++)
        {
            for(int col=0; col<words[row].size(); col++)
            {
                if(col >= words.size() || row >= words[col].size() || words[row][col]!=words[col][row])
                    return false;
            }
        }

        return true;
    }
};