/*
409. Longest Palindrome
Easy
4.7K
301
company
Amazon
company
Apple
company
Google

Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

 

Example 1:

Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.

Example 2:

Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.

 

Constraints:

    1 <= s.length <= 2000
    s consists of lowercase and/or uppercase English letters only.

Accepted
524.6K
Submissions
970.1K
Acceptance Rate
54.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (25)
Similar Questions
Palindrome Permutation
Easy
Longest Palindrome by Concatenating Two Letter Words
Medium
Largest Palindromic Number
Medium
Related Topics
Hash Table
String
Greedy
*/
class Solution {
public:
    int longestPalindrome(string s) {
        int longest_palindrome = 0;
        map<char, int> map_palindrome;
        int flag = 0;

        for(char c:s)       
            map_palindrome[c]++;
            
        for(auto palindrome : map_palindrome)
        {
            longest_palindrome += palindrome.second & 1 ? palindrome.second-1 : palindrome.second;
            if(!flag && (palindrome.second & 1))       
                flag = 1;
        }
        
        return longest_palindrome + flag;
    }
};