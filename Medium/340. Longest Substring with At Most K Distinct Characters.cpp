/*
340. Longest Substring with At Most K Distinct Characters
Medium
2.7K
77
company
Yandex
company
Amazon
company
Google

Given a string s and an integer k, return the length of the longest
substring
of s that contains at most k distinct characters.

 

Example 1:

Input: s = "eceba", k = 2
Output: 3
Explanation: The substring is "ece" with length 3.

Example 2:

Input: s = "aa", k = 1
Output: 2
Explanation: The substring is "aa" with length 2.

 

Constraints:

    1 <= s.length <= 5 * 104
    0 <= k <= 50

Accepted
317.1K
Submissions
657.9K
Acceptance Rate
48.2%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (4)
Similar Questions
Longest Substring Without Repeating Characters
Medium
Longest Substring with At Most Two Distinct Characters
Medium
Longest Repeating Character Replacement
Medium
Subarrays with K Different Integers
Hard
Max Consecutive Ones III
Medium
Maximize the Confusion of an Exam
Medium
Related Topics
Hash Table
String
Sliding Window
*/

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int s_len = s.size();
        int len_distinct = 0;
        map<char, int> char_counter;

        for(int right = 0; right < s_len; right++)
        {
            char_counter[s[right]]++;

            if(char_counter.size() <= k)
                len_distinct++;
            else
            {
                char_counter[s[right - len_distinct]]--;
                
                if(!char_counter[s[right - len_distinct]])
                    char_counter.erase(s[right - len_distinct]);
            }
        }

        return len_distinct;
    }
};