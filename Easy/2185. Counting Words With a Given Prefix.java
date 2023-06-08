/*
2185. Counting Words With a Given Prefix
Easy
549
14
company
Google
company
Microsoft

You are given an array of strings words and a string pref.

Return the number of strings in words that contain pref as a prefix.

A prefix of a string s is any leading contiguous substring of s.

 

Example 1:

Input: words = ["pay","attention","practice","attend"], pref = "at"
Output: 2
Explanation: The 2 strings that contain "at" as a prefix are: "attention" and "attend".

Example 2:

Input: words = ["leetcode","win","loops","success"], pref = "code"
Output: 0
Explanation: There are no strings that contain "code" as a prefix.

 

Constraints:

    1 <= words.length <= 100
    1 <= words[i].length, pref.length <= 100
    words[i] and pref consist of lowercase English letters.

Accepted
65.5K
Submissions
84.9K
Acceptance Rate
77.2%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (6)
Similar Questions
Check If a Word Occurs As a Prefix of Any Word in a Sentence
Easy
Count Prefixes of a Given String
Easy
Related Topics
Array
String
*/
class Solution {
    public int prefixCount(String[] words, String pref) {
        int prefix_count = 0;
        for(int i=0; i<words.length; i++)
            if(words[i].startsWith(pref))
                prefix_count++;

        return prefix_count;
    }
}