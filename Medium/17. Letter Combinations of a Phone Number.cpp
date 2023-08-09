/*
17. Letter Combinations of a Phone Number
Medium
16.7K
887
company
Amazon
company
Apple
company
Bloomberg

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:

Input: digits = ""
Output: []

Example 3:

Input: digits = "2"
Output: ["a","b","c"]

 

Constraints:

    0 <= digits.length <= 4
    digits[i] is a digit in the range ['2', '9'].

Accepted
1.7M
Submissions
2.9M
Acceptance Rate
58.2%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (102)
Similar Questions
Generate Parentheses
Medium
Combination Sum
Medium
Binary Watch
Easy
Count Number of Texts
Medium
Related Topics
Hash Table
String
Backtracking
*/

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(!digits.size())
            return {};

        vector<string> buttons{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        vector<string> letter_combinations;
        letter_combinations.push_back("");

        for(char num : digits)
        {
            vector<string> temp;
            
            for(string combinations : letter_combinations)
                for(char combain : buttons[num - '0'])
                    temp.push_back(combinations + combain);

            letter_combinations.swap(temp);
        }

        return letter_combinations;
    }
};