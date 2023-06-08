/*
1309. Decrypt String from Alphabet to Integer Mapping
Easy
1.4K
101
Quip (Salesforce)

You are given a string s formed by digits and '#'. We want to map s to English lowercase characters as follows:

    Characters ('a' to 'i') are represented by ('1' to '9') respectively.
    Characters ('j' to 'z') are represented by ('10#' to '26#') respectively.

Return the string formed after mapping.

The test cases are generated so that a unique mapping will always exist.

 

Example 1:

Input: s = "10#11#12"
Output: "jkab"
Explanation: "j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".

Example 2:

Input: s = "1326#"
Output: "acz"

 

Constraints:

    1 <= s.length <= 1000
    s consists of digits and the '#' letter.
    s will be a valid string such that mapping is always possible.

Accepted
109.7K
Submissions
137.6K
Acceptance Rate
79.7%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (4)
Related Topics
String
*/
class Solution {
public:
    string freqAlphabets(string s) {
        string freq_alphabets = "";
        int i = s.size() - 1;
        
        while(i >= 0)
        {
            char si = s[i];
            int t = 0;
            if(si == '#')
            {
                t += s[i - 2] - '0';
                t = (t * 10) + (s[i - 1] - '0'); 
                i -= 3;
            }
            else
                t = s[i--] - '0';

            freq_alphabets = (char)(t + 'a' - 1) + freq_alphabets;
        }

        return freq_alphabets;
    }
};