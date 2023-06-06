/*
424. Longest Repeating Character Replacement
Medium
8.2K
348
company
Google
company
Amazon
company
Uber

You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

 

Example 1:

Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Example 2:

Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.
There may exists other ways to achive this answer too.

 

Constraints:

    1 <= s.length <= 105
    s consists of only uppercase English letters.
    0 <= k <= s.length

Accepted
461.9K
Submissions
886.1K
Acceptance Rate
52.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (29)
Similar Questions
Longest Substring with At Most K Distinct Characters
Medium
Max Consecutive Ones III
Medium
Minimum Number of Operations to Make Array Continuous
Hard
Maximize the Confusion of an Exam
Medium
Longest Substring of One Repeating Character
Hard
Related Topics
Hash Table
String
Sliding Window
*/
class Solution {
    public int characterReplacement(String s, int k) {
        int start = 0;
        int[] frequencyMap = new int[26];
        int maxFrequency = 0;
        int longestSubstringLength = 0;

        for (int end = 0; end < s.length(); end += 1) 
        {
            int currentChar = s.charAt(end) - 'A';

            frequencyMap[currentChar] += 1;
            maxFrequency = Math.max(maxFrequency, frequencyMap[currentChar]);

            Boolean isValid = (end + 1 - start - maxFrequency <= k);

            if (!isValid) 
            {
                int outgoingChar = s.charAt(start) - 'A';

                frequencyMap[outgoingChar] -= 1;
                start += 1;
            }

            longestSubstringLength = end + 1 - start;
        }

        return longestSubstringLength;
    }
}