/*
1456. Maximum Number of Vowels in a Substring of Given Length
Medium
2.7K
89
company
Amazon

Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.

Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

 

Example 1:

Input: s = "abciiidef", k = 3
Output: 3
Explanation: The substring "iii" contains 3 vowel letters.

Example 2:

Input: s = "aeiou", k = 2
Output: 2
Explanation: Any substring of length 2 contains 2 vowels.

Example 3:

Input: s = "leetcode", k = 3
Output: 2
Explanation: "lee", "eet" and "ode" contain 2 vowels.

 

Constraints:

    1 <= s.length <= 105
    s consists of lowercase English letters.
    1 <= k <= s.length

Accepted
144.3K
Submissions
247.4K
Acceptance Rate
58.3%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (55)
Similar Questions
Maximum White Tiles Covered by a Carpet
Medium
Minimum Recolors to Get K Consecutive Black Blocks
Easy
Length of the Longest Alphabetical Continuous Substring
Medium
Related Topics
String
Sliding Window

*/
class Solution {
public:    
    int maxVowels(string s, int k) {  
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};                  
        int count = 0;         
        for (int i = 0; i < k; i++)              
            count += vowels.count(s[i]);                  
        int answer = count;                 
        for (int i = k; i < s.length(); i++) 
        {             
            count += vowels.count(s[i]) - vowels.count(s[i - k]);             
            answer = max(answer, count);         
        }                  
        return answer;     
    }
};