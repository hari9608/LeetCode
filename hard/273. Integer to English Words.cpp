/*
273. Integer to English Words
Hard
company
Apple
company
Palantir Technologies
company
Amazon

Convert a non-negative integer num to its English words representation.

Example 1:

Input: num = 123
Output: "One Hundred Twenty Three"

Example 2:

Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"

Example 3:

Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

Constraints:

    0 <= num <= 231 - 1

Similar Questions
Integer to Roman
Medium

Related Topics
Math
String
Recursion
*/

class Solution {
public:
    vector<string> ones = {"","One","Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    vector<string> teen = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    vector<string> tens = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    string twoDig(int num)
    {
        if(!num)        return "";
        else if(num < 10)       return  ones[num];
        else if(num < 20)       return  teen[num - 10];
        else 
        {
            int tenner = num / 10;
            int rest = num % 10;
            if(rest)    return tens[tenner] + " " + ones[rest];
            else        return tens[tenner];
        }
    }

    string threeDig(int num)
    {
        int hundreds = num / 100;
        int rest = num % 100;

        if(hundreds && rest)    return ones[hundreds] + " Hundred " + twoDig(rest);
        if(hundreds && !rest)   return ones[hundreds] + " Hundred";
        if(!hundreds && rest)   return twoDig(rest);
        return "";
    }

    string numberToWords(int num) {
        if(num == 0)        return "Zero";

        int billion = num / 1000000000;
        int million = num % 1000000000 / 1000000;
        int thousand = num % 1000000 / 1000;
        int rest = num % 1000;

        string number_to_words = "";
        if(billion)     number_to_words = threeDig(billion) + " Billion";
        if(million)
        {
            if(number_to_words.size() > 0)  number_to_words += " ";
            number_to_words += threeDig(million) + " Million";
        }
        if(thousand)
        {
            if(number_to_words.size() > 0)  number_to_words += " ";
            number_to_words += threeDig(thousand) + " Thousand";
        }
        if(rest)
        {
            if(number_to_words.size() > 0)  number_to_words += " ";
            number_to_words += threeDig(rest);
        }

        return number_to_words;
    }
};