/*
14. Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

 

Constraints:

    1 <= strs.length <= 200
    0 <= strs[i].length <= 200
    strs[i] consists of only lowercase English letters.


*/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int lcpLen = strs[0].length();
        for(int i=1; i<n; i++){
            int ma=0;
            while(ma<strs[i].length() && strs[0][ma]==strs[i][ma]) ma++;
            lcpLen = min(ma, lcpLen);
        }
        return strs[0].substr(0,lcpLen);
        
    }
};