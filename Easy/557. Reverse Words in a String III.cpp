/*
557. Reverse Words in a String III
Easy
4.9K
228
company
Yandex
company
Facebook
company
Amazon

Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

 

Example 1:

Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Example 2:

Input: s = "God Ding"
Output: "doG gniD"

 

Constraints:

    1 <= s.length <= 5 * 104
    s contains printable ASCII characters.
    s does not contain any leading or trailing spaces.
    There is at least one word in s.
    All the words in s are separated by a single space.

Accepted
696.6K
Submissions
850.2K
Acceptance Rate
81.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (29)
Similar Questions
Reverse String II
Easy
Related Topics
Two Pointers
String
*/
class Solution {
public:
    string reverseWords(string s) {
        stack<char> storage;
        int s_len = s.size();
        string reverse_words;

        for(int i = 0; i < s_len; i++)
            if(s[i] == ' ')
            {
                while(!storage.empty())
                {
                    reverse_words += storage.top();
                    storage.pop();
                }
                reverse_words += ' ';
            }
            else
                storage.push(s[i]);
        
        
        while(!storage.empty())
        {
            reverse_words += storage.top();
            storage.pop();
        }
        
        return reverse_words;
    }
};