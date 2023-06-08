/*
2108. Find First Palindromic String in the Array
Easy
817
29

Given an array of strings words, return the first palindromic string in the array. If there is no such string, return an empty string "".

A string is palindromic if it reads the same forward and backward.

 

Example 1:

Input: words = ["abc","car","ada","racecar","cool"]
Output: "ada"
Explanation: The first string that is palindromic is "ada".
Note that "racecar" is also palindromic, but it is not the first.

Example 2:

Input: words = ["notapalindrome","racecar"]
Output: "racecar"
Explanation: The first and only string that is palindromic is "racecar".

Example 3:

Input: words = ["def","ghi"]
Output: ""
Explanation: There are no palindromic strings, so the empty string is returned.

 

Constraints:

    1 <= words.length <= 100
    1 <= words[i].length <= 100
    words[i] consists only of lowercase English letters.

Accepted
88.9K
Submissions
113.1K
Acceptance Rate
78.6%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (10)
Similar Questions
Valid Palindrome
Easy
Related Topics
Array
Two Pointers
String
*/
class Solution {
public:
    bool isPalindrome(string word)
    {
        int left = 0;
        int right = word.size()-1;

        while(left <= right)
            if(word[left++] == word[right--]);
            else                return false;
        return true;
    }

    string firstPalindrome(vector<string>& words) {
        for(auto word : words)  
            if(isPalindrome(word))  
                return word;
        return "";
    }
};