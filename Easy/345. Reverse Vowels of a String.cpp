/*
345. Reverse Vowels of a String
Easy
3.5K
2.4K
company
Apple
company
Yahoo
company
Uber

Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 

Example 1:

Input: s = "hello"
Output: "holle"

Example 2:

Input: s = "leetcode"
Output: "leotcede"

 

Constraints:

    1 <= s.length <= 3 * 105
    s consist of printable ASCII characters.

Accepted
518.6K
Submissions
1M
Acceptance Rate
50.4%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (56)
Similar Questions
Reverse String
Easy
Remove Vowels from a String
Easy
Related Topics
Two Pointers
String
*/
class Solution {
public:
    bool isVowel(char c)
    {
        c = tolower(c);
        return (c=='a' || c=='e' || c=='i' || c=='o' || c=='u');
    }
    string reverseVowels(string s) {
        int left = 0;
        int right = s.size() - 1;

        while(left < right)
        {
            if(isVowel(s[left]) && isVowel(s[right]))
            {
                char temp = s[left];
                s[left]  = s[right];
                s[right] = temp;

                left++;
                right--;
            }

            if(!isVowel(s[left]))       
                left++;
                
            if(!isVowel(s[right]))      
                right--;
        }

        return s;
    }
};