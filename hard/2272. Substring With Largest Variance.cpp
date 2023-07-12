/*
2272. Substring With Largest Variance
Hard
1.7K
188
company
Amazon

The variance of a string is defined as the largest difference between the number of occurrences of any 2 characters present in the string. Note the two characters may or may not be the same.

Given a string s consisting of lowercase English letters only, return the largest variance possible among all substrings of s.

A substring is a contiguous sequence of characters within a string.

 

Example 1:

Input: s = "aababbb"
Output: 3
Explanation:
All possible variances along with their respective substrings are listed below:
- Variance 0 for substrings "a", "aa", "ab", "abab", "aababb", "ba", "b", "bb", and "bbb".
- Variance 1 for substrings "aab", "aba", "abb", "aabab", "ababb", "aababbb", and "bab".
- Variance 2 for substrings "aaba", "ababbb", "abbb", and "babb".
- Variance 3 for substring "babbb".
Since the largest possible variance is 3, we return it.

Example 2:

Input: s = "abcde"
Output: 0
Explanation:
No letter occurs more than once in s, so the variance of every substring is 0.

 

Constraints:

    1 <= s.length <= 104
    s consists of lowercase English letters.

Accepted
60.7K
Submissions
127.8K
Acceptance Rate
47.5%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (62)
Similar Questions
Maximum Subarray
Medium
Related Topics
Array
Dynamic Programming
*/

class Solution {
public:
    int largestVariance(string s) {
        vector<int> counter(26, 0);
        int largest_variance = 0;

        for (char ch : s) 
            counter[ch - 'a']++;
        
        for (int i = 0; i < 26; i++) 
        {
            for (int j = 0; j < 26; j++) 
            {
                if (i == j || counter[i] == 0 || counter[j] == 0) 
                    continue;
                
                char major = 'a' + i;
                char minor = 'a' + j;
                int major_char_count = 0;
                int minor_char_count = 0;
                
                int rest_minor = counter[j];
                
                for (char ch : s) 
                {
                    if (ch == major) 
                        major_char_count++;
                    
                    if (ch == minor) 
                    {
                        minor_char_count++;
                        rest_minor--;
                    }
                    
                    if (minor_char_count > 0)
                        largest_variance = max(largest_variance, major_char_count - minor_char_count);
                    
                    if (major_char_count < minor_char_count && rest_minor > 0) 
                    {
                        major_char_count = 0;
                        minor_char_count = 0;
                    }
                }
            }
        }
        
        return largest_variance;
    }
};