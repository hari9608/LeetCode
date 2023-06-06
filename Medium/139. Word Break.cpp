/*
139. Word Break
Medium
14.1K
591
company
Amazon
company
Bloomberg
company
Facebook

Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.

 

Example 1:

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.

Example 3:

Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false

 

Constraints:

    1 <= s.length <= 300
    1 <= wordDict.length <= 1000
    1 <= wordDict[i].length <= 20
    s and wordDict[i] consist of only lowercase English letters.
    All the strings of wordDict are unique.

Accepted
1.3M
Submissions
2.9M
Acceptance Rate
45.7%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (41)
Similar Questions
Word Break II
Hard
Extra Characters in a String
Medium
Related Topics
Array
Hash Table
String
Dynamic Programming
Trie
Memoization
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> word_set(wordDict.begin(), wordDict.end());
        vector<bool> dp(s.length() + 1);
        dp[0] = true;

        for (int i = 1; i <= s.length(); i++) 
            for (int j = 0; j < i; j++) 
                if (dp[j] && word_set.find(s.substr(j, i - j)) != word_set.end()) 
                {
                    dp[i] = true;
                    break;
                }

        return dp[s.length()];
    }
};