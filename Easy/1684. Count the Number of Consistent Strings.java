/*
1684. Count the Number of Consistent Strings
Easy
1.5K
59
company
Robinhood

You are given a string allowed consisting of distinct characters and an array of strings words. A string is consistent if all characters in the string appear in the string allowed.

Return the number of consistent strings in the array words.

 

Example 1:

Input: allowed = "ab", words = ["ad","bd","aaab","baa","badab"]
Output: 2
Explanation: Strings "aaab" and "baa" are consistent since they only contain characters 'a' and 'b'.

Example 2:

Input: allowed = "abc", words = ["a","b","c","ab","ac","bc","abc"]
Output: 7
Explanation: All strings are consistent.

Example 3:

Input: allowed = "cad", words = ["cc","acd","b","ba","bac","bad","ac","d"]
Output: 4
Explanation: Strings "cc", "acd", "ac", and "d" are consistent.

 

Constraints:

    1 <= words.length <= 104
    1 <= allowed.length <= 26
    1 <= words[i].length <= 10
    The characters in allowed are distinct.
    words[i] and allowed contain only lowercase English letters.

Accepted
133K
Submissions
161.5K
Acceptance Rate
82.3%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (9)
Similar Questions
Count Pairs Of Similar Strings
Easy
Related Topics
Array
Hash Table
String
Bit Manipulation
*/
class Solution {
    public int countConsistentStrings(String allowed, String[] words) {
        int no_allowed_count = 0;

        for(String word : words)
            for(int i=0; i<word.length(); i++)
                if(!allowed.contains(word.substring(i,i+1)))
                {
                    no_allowed_count++;
                    break;
                }
                
        return words.length - no_allowed_count;
    }
}