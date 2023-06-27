/*
1189. Maximum Number of Balloons
Easy
1.5K
84
company
Tesla
company
Microsoft
company
Adobe

Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.

 

Example 1:

Input: text = "nlaebolko"
Output: 1

Example 2:

Input: text = "loonbalxballpoon"
Output: 2

Example 3:

Input: text = "leetcode"
Output: 0

 

Constraints:

    1 <= text.length <= 104
    text consists of lower case English letters only.

Accepted
154K
Submissions
253.9K
Acceptance Rate
60.7%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (5)
Related Topics
Hash Table
String
Counting
*/
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int b_count = 0;
        int a_count = 0;
        int l_count = 0;
        int o_count = 0;
        int n_count = 0;

        for(char t : text)
        {
            b_count += t == 'b';
            a_count += t == 'a';
            l_count += t == 'l';
            o_count += t == 'o';
            n_count += t == 'n';
        }

        l_count /= 2;
        o_count /= 2;

        return min(b_count, min(min(a_count, l_count), min(o_count, n_count)  ));
    }
};