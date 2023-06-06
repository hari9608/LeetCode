/*
651. 4 Keys Keyboard
Medium
654
86
company
Microsoft
company
Google

Imagine you have a special keyboard with the following keys:

    A: Print one 'A' on the screen.
    Ctrl-A: Select the whole screen.
    Ctrl-C: Copy selection to buffer.
    Ctrl-V: Print buffer on screen appending it after what has already been printed.

Given an integer n, return the maximum number of 'A' you can print on the screen with at most n presses on the keys.

 

Example 1:

Input: n = 3
Output: 3
Explanation: We can at most get 3 A's on screen by pressing the following key sequence:
A, A, A

Example 2:

Input: n = 7
Output: 9
Explanation: We can at most get 9 A's on screen by pressing following key sequence:
A, A, A, Ctrl A, Ctrl C, Ctrl V, Ctrl V

 

Constraints:

    1 <= n <= 50

Accepted
26.6K
Submissions
47.7K
Acceptance Rate
55.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (3)
Similar Questions
2 Keys Keyboard
Medium
Related Topics
Math
Dynamic Programming
*/
class Solution {
public:
    int maxA(int n) {
        vector<int> screen;
        screen.push_back(0);

        for(int i=1; i<=n; i++)     screen.push_back(i);
        
        for (int i = 0; i <= n - 3; i++) 
            for (int j = i + 3; j <= min(n, i + 6); j++)
                screen[j] = max(screen[j], (j - i - 1) * screen[i]);
        
        return screen[n];
    }
};