/*
438. Find All Anagrams in a String
Medium
11.3K
315
company
Yandex
company
Amazon
company
Adobe

Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:

Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

 

Constraints:

    1 <= s.length, p.length <= 3 * 104
    s and p consist of lowercase English letters.

Accepted
767.7K
Submissions
1.5M
Acceptance Rate
50.2%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (81)
Similar Questions
Valid Anagram
Easy
Permutation in String
Medium
Related Topics
Hash Table
String
Sliding Window
*/
class Solution {
  public List<Integer> findAnagrams(String s, String p) {
    int ns = s.length();
    int np = p.length();

    if (ns < np) 
      return new ArrayList();

    int [] pCount = new int[26];
    int [] sCount = new int[26];
    
    for (char ch : p.toCharArray())
      pCount[(int)(ch - 'a')]++;

    List<Integer> output = new ArrayList();
    
    for (int i = 0; i < ns; ++i) 
    {
      sCount[(int)(s.charAt(i) - 'a')]++;
      
      if (i >= np)
        sCount[(int)(s.charAt(i - np) - 'a')]--;
      
      if (Arrays.equals(pCount, sCount))
        output.add(i - np + 1);
    }

    return output;
  }
}