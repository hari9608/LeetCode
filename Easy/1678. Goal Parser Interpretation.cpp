/*
1678. Goal Parser Interpretation
Easy
1.3K
82
company
Apple

You own a Goal Parser that can interpret a string command. The command consists of an alphabet of "G", "()" and/or "(al)" in some order. The Goal Parser will interpret "G" as the string "G", "()" as the string "o", and "(al)" as the string "al". The interpreted strings are then concatenated in the original order.

Given the string command, return the Goal Parser's interpretation of command.

 

Example 1:

Input: command = "G()(al)"
Output: "Goal"
Explanation: The Goal Parser interprets the command as follows:
G -> G
() -> o
(al) -> al
The final concatenated result is "Goal".

Example 2:

Input: command = "G()()()()(al)"
Output: "Gooooal"

Example 3:

Input: command = "(al)G(al)()()G"
Output: "alGalooG"

 

Constraints:

    1 <= command.length <= 100
    command consists of "G", "()", and/or "(al)" in some order.

Accepted
187K
Submissions
215.7K
Acceptance Rate
86.7%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (17)
Related Topics
String
*/
class Solution {
public:
    string interpret(string command) {
        string interpret;
        
        for(int i=0;i<command.size();i++)
        {
            if(command[i]=='G')
                interpret.push_back('G');

            else if(command[i]=='(')
                if(command[i+1]==')')
                {
                    interpret.push_back('o');
                }
                else
                {
                    interpret.push_back('a');
                    interpret.push_back('l');
                }
            
        }
        return interpret;
    }
};