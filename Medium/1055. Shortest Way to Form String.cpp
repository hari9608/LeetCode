/*
1055. Shortest Way to Form String
Medium
1.2K
63
company
Google
company
Facebook

A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Given two strings source and target, return the minimum number of subsequences of source such that their concatenation equals target. If the task is impossible, return -1.

 

Example 1:

Input: source = "abc", target = "abcbc"
Output: 2
Explanation: The target "abcbc" can be formed by "abc" and "bc", which are subsequences of source "abc".

Example 2:

Input: source = "abc", target = "acdbc"
Output: -1
Explanation: The target string cannot be constructed from the subsequences of source string due to the character "d" in target string.

Example 3:

Input: source = "xyz", target = "xzyxz"
Output: 3
Explanation: The target string can be constructed as follows "xz" + "y" + "xz".

 

Constraints:

    1 <= source.length, target.length <= 1000
    source and target consist of lowercase English letters.

Accepted
78.3K
Submissions
131.1K
Acceptance Rate
59.7%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (6)
Similar Questions
Is Subsequence
Easy
Number of Matching Subsequences
Medium
Related Topics
Two Pointers
String
Greedy

*/
class Solution {
public:
    int shortestWay(string source, string target) {
        int tar = 0;
        int min_subsequence = 0;

        while(tar < target.size())
        {
            int flag = 1;
            for(int sou=0; sou<source.size(); sou++)
            {
                if(target[tar] == source[sou])  tar++, flag = 0;
            }
            if(flag) return -1;
            min_subsequence++;
        }

        return min_subsequence;
    }
};
