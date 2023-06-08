/*
1768. Merge Strings Alternately
Easy
2.2K
40
company
Amazon
company
Google
company
Uber

You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.

Return the merged string.

 

Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r

Example 2:

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s

Example 3:

Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d

 

Constraints:

    1 <= word1.length, word2.length <= 100
    word1 and word2 consist of lowercase English letters.

Accepted
224.1K
Submissions
272.1K
Acceptance Rate
82.3%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (35)
Similar Questions
Zigzag Iterator
Medium
Minimum Additions to Make Valid String
Medium
Related Topics
Two Pointers
String
*/
class Solution {
    public String mergeAlternately(String word1, String word2) {
        int word1_len = word1.length();
        int word2_len = word2.length();
        String result = "";
        
        for(int ind = 0; ind < word1_len || ind < word2_len; ind++)
        {
            if(ind < word1_len)     result += word1.charAt(ind);
            if(ind < word2_len)     result += word2.charAt(ind);
        }

        return result;
    }
}