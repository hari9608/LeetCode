/*
290. Word Pattern
Easy
6.3K
761
company
Amazon
Bolt
company
Adobe

Given a pattern and a string s, find if s follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in s.

 

Example 1:

Input: pattern = "abba", s = "dog cat cat dog"
Output: true

Example 2:

Input: pattern = "abba", s = "dog cat cat fish"
Output: false

Example 3:

Input: pattern = "aaaa", s = "dog cat cat dog"
Output: false

 

Constraints:

    1 <= pattern.length <= 300
    pattern contains only lower-case English letters.
    1 <= s.length <= 3000
    s contains only lowercase English letters and spaces ' '.
    s does not contain any leading or trailing spaces.
    All the words in s are separated by a single space.

Accepted
531.1K
Submissions
1.3M
Acceptance Rate
41.7%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (126)
Similar Questions
Isomorphic Strings
Easy
Word Pattern II
Medium
Related Topics
Hash Table
String
*/
class Solution {
    public boolean wordPattern(String pattern, String s) {
        HashMap word_index = new HashMap();
        String[] words = s.split(" ");

        if(words.length != pattern.length())
            return false;

        for(Integer ind = 0; ind < words.length; ind++)
        {
            char c = pattern.charAt(ind);
            String word = words[ind];
            if(!word_index.containsKey(c))  
                word_index.put(c, ind);

            if(!word_index.containsKey(word))  
                word_index.put(word, ind);

            if(word_index.get(c) != word_index.get(word))   
                return false;
        }

        return true;
    }
}