/*
2224. Minimum Number of Operations to Convert Time
Easy
374
32
company
Google

You are given two strings current and correct representing two 24-hour times.

24-hour times are formatted as "HH:MM", where HH is between 00 and 23, and MM is between 00 and 59. The earliest 24-hour time is 00:00, and the latest is 23:59.

In one operation you can increase the time current by 1, 5, 15, or 60 minutes. You can perform this operation any number of times.

Return the minimum number of operations needed to convert current to correct.

 

Example 1:

Input: current = "02:30", correct = "04:35"
Output: 3
Explanation:
We can convert current to correct in 3 operations as follows:
- Add 60 minutes to current. current becomes "03:30".
- Add 60 minutes to current. current becomes "04:30".
- Add 5 minutes to current. current becomes "04:35".
It can be proven that it is not possible to convert current to correct in fewer than 3 operations.

Example 2:

Input: current = "11:00", correct = "11:01"
Output: 1
Explanation: We only have to add one minute to current, so the minimum number of operations needed is 1.

 

Constraints:

    current and correct are in the format "HH:MM"
    current <= correct

Accepted
33.2K
Submissions
51.3K
Acceptance Rate
64.8%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (2)
Similar Questions
Coin Change
Medium
Design an ATM Machine
Medium
Count Days Spent Together
Easy
Related Topics
String
Greedy
*/
class Solution {
public:
    int convertTime(string current, string correct) {
        int current_hour = (current[0] - '0')*10 + (current[1] - '0');
        int current_minu = (current[3] - '0')*10 + (current[4] - '0');
        int correct_hour = (correct[0] - '0')*10 + (correct[1] - '0');
        int correct_minu = (correct[3] - '0')*10 + (correct[4] - '0');

        int convert_time = correct_hour - current_hour;
        int minute_change = correct_minu + 60 - current_minu;

        if(correct_minu < current_minu)     convert_time--;
        else                                minute_change -= 60;
        
        convert_time += (minute_change / 15);
        minute_change = minute_change % 15;

        convert_time += (minute_change / 5);
        minute_change = minute_change % 5;
        
        convert_time += minute_change;

        return convert_time;
    }
};