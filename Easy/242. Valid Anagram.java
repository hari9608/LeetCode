/*
242. Valid Anagram
Easy
9.3K
290
company
Amazon
company
Bloomberg
company
Apple

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true

Example 2:

Input: s = "rat", t = "car"
Output: false

 

Constraints:

    1 <= s.length, t.length <= 5 * 104
    s and t consist of lowercase English letters.

 

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
Accepted
2.2M
Submissions
3.5M
Acceptance Rate
63.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (70)
Similar Questions
Group Anagrams
Medium
Palindrome Permutation
Easy
Find All Anagrams in a String
Medium
Find Resultant Array After Removing Anagrams
Easy
Related Topics
Hash Table
String
Sorting
*/
class Solution {
    public boolean isAnagram(String s, String t) {
        if (s.length() != t.length())   
            return false;
        
        int[] counter = new int[26];

        for (int i = 0; i < s.length(); i++) 
        {
            counter[s.charAt(i) - 'a']++;
            counter[t.charAt(i) - 'a']--;
        }

        for (int count : counter) 
            if (count != 0)
                return false;
            
        return true;
    }
}