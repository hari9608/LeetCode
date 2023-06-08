/*
520. Detect Capital
Easy
3.2K
446
company
Google
company
Amazon

We define the usage of capitals in a word to be right when one of the following cases holds:

    All letters in this word are capitals, like "USA".
    All letters in this word are not capitals, like "leetcode".
    Only the first letter in this word is capital, like "Google".

Given a string word, return true if the usage of capitals in it is right.

 

Example 1:

Input: word = "USA"
Output: true

Example 2:

Input: word = "FlaG"
Output: false

 

Constraints:

    1 <= word.length <= 100
    word consists of lowercase and uppercase English letters.

Accepted
392.1K
Submissions
688.7K
Acceptance Rate
56.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (71)
Similar Questions
Capitalize the Title
Easy
Related Topics
String
*/
class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() == 1)    
            return true;

        bool lower = false;
        bool upper = false;

        for(int ind=1; ind<word.size(); ind++)
        {
            if(lower && isupper(word[ind]))     return false;

            if(isupper(word[ind]))      upper = true;
            else                        lower = true;
        }
        
        return lower ^ upper;
    }
};