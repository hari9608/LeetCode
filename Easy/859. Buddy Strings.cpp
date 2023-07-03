/*
859. Buddy Strings
Easy
2.6K
1.5K
company
DoorDash
company
Square
company
Facebook

Given two strings s and goal, return true if you can swap two letters in s so the result is equal to goal, otherwise, return false.

Swapping letters is defined as taking two indices i and j (0-indexed) such that i != j and swapping the characters at s[i] and s[j].

    For example, swapping at indices 0 and 2 in "abcd" results in "cbad".

 

Example 1:

Input: s = "ab", goal = "ba"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'b' to get "ba", which is equal to goal.

Example 2:

Input: s = "ab", goal = "ab"
Output: false
Explanation: The only letters you can swap are s[0] = 'a' and s[1] = 'b', which results in "ba" != goal.

Example 3:

Input: s = "aa", goal = "aa"
Output: true
Explanation: You can swap s[0] = 'a' and s[1] = 'a' to get "aa", which is equal to goal.

 

Constraints:

    1 <= s.length, goal.length <= 2 * 104
    s and goal consist of lowercase letters.

Accepted
190.6K
Submissions
595.5K
Acceptance Rate
32.0%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (69)
Similar Questions
Determine if Two Strings Are Close
Medium
Check if One String Swap Can Make Strings Equal
Easy
Make Number of Distinct Characters Equal
Medium
Related Topics
Hash Table
String
*/
class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size())
            return false;

        if(s == goal)
        {
            map<char, int> frequency;
            
            for(auto& ch : s)
            {
                if(frequency[ch])
                    return true;

                frequency[ch]++;                
            }

            return false;
        }

        int ind_01 = -1;
        int ind_02 = -1;

        for(int ind = 0; ind < s.size(); ind++)
        {
            if(s[ind] != goal[ind])
            {
                if(ind_01 == -1)
                    ind_01 = ind;
                else if(ind_02 == -1)
                    ind_02 = ind;
                else                    // more than two char un equal
                    return false;
            }
        }

        return ind_02 == -1 ? false : (s[ind_01] == goal[ind_02] && s[ind_02] == goal[ind_01]);
    }
};