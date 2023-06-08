/*
28. Find the Index of the First Occurrence in a String
Easy
3.6K
189
company
Amazon
company
Bloomberg
company
Microsoft

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

 

Constraints:

    1 <= haystack.length, needle.length <= 104
    haystack and needle consist of only lowercase English characters.

Accepted
1.8M
Submissions
4.5M
Acceptance Rate
39.5%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (118)
Similar Questions
Shortest Palindrome
Hard
Repeated Substring Pattern
Easy
Related Topics
Two Pointers
String
String Matching
*/
class Solution {
    public int strStr(String haystack, String needle) {
        return haystack.indexOf(needle);
    }
}