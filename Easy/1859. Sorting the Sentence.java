/*
1859. Sorting the Sentence
Easy
1.8K
57
company
Facebook
company
Google
company
Amazon

A sentence is a list of words that are separated by a single space with no leading or trailing spaces. Each word consists of lowercase and uppercase English letters.

A sentence can be shuffled by appending the 1-indexed word position to each word then rearranging the words in the sentence.

    For example, the sentence "This is a sentence" can be shuffled as "sentence4 a3 is2 This1" or "is2 sentence4 This1 a3".

Given a shuffled sentence s containing no more than 9 words, reconstruct and return the original sentence.

 

Example 1:

Input: s = "is2 sentence4 This1 a3"
Output: "This is a sentence"
Explanation: Sort the words in s to their original positions "This1 is2 a3 sentence4", then remove the numbers.

Example 2:

Input: s = "Myself2 Me1 I4 and3"
Output: "Me Myself and I"
Explanation: Sort the words in s to their original positions "Me1 Myself2 and3 I4", then remove the numbers.

 

Constraints:

    2 <= s.length <= 200
    s consists of lowercase and uppercase English letters, spaces, and digits from 1 to 9.
    The number of words in s is between 1 and 9.
    The words in s are separated by a single space.
    s contains no leading or trailing spaces.

Accepted
118.1K
Submissions
141.2K
Acceptance Rate
83.7%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (11)
Similar Questions
Check if Numbers Are Ascending in a Sentence
Easy
Related Topics
String
Sorting
*/
class Solution {
    public String sortSentence(String s) {
        
        String[] strarr = s.split(" ");
        int len = strarr.length;
        String[] ans = new String[len+1];
        int need_to_store_position;
        int temlen;

        for(int i=0; i<len; i++)
        {
            System.out.println(strarr[i]);
            temlen = strarr[i].length();
            need_to_store_position = Integer.valueOf(strarr[i].substring(temlen-1));
            ans[need_to_store_position] = strarr[i].substring(0,temlen-1);
        }
        String sort_sentence = "";
        for(int i=1; i<len; i++){
            sort_sentence += ans[i] + " ";
        }
        return sort_sentence + ans[len];
    }
}