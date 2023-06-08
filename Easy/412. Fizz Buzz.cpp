/*
412. Fizz Buzz
Easy
2K
276
company
Amazon
company
Google
company
IBM

Given an integer n, return a string array answer (1-indexed) where:

    answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
    answer[i] == "Fizz" if i is divisible by 3.
    answer[i] == "Buzz" if i is divisible by 5.
    answer[i] == i (as a string) if none of the above conditions are true.

 

Example 1:

Input: n = 3
Output: ["1","2","Fizz"]

Example 2:

Input: n = 5
Output: ["1","2","Fizz","4","Buzz"]

Example 3:

Input: n = 15
Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]

 

Constraints:

    1 <= n <= 104

Accepted
984.4K
Submissions
1.4M
Acceptance Rate
70.3%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (38)
Similar Questions
Fizz Buzz Multithreaded
Medium
Categorize Box According to Criteria
Easy
Related Topics
Math
String
Simulation
*/
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;

        for(int index=1; index<=n; index++){
            bool is_divisible_by_3 = index%3==0;
            bool is_divisible_by_5 = index%5==0;
            if(is_divisible_by_3 && is_divisible_by_5)  result.push_back("FizzBuzz");
            else if(is_divisible_by_3)                  result.push_back("Fizz");
            else if(is_divisible_by_5)                  result.push_back("Buzz");
            else                                        result.push_back(to_string(index));
        }

        return result; 
    }
};