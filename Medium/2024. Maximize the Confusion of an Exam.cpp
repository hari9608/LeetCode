/*
2024. Maximize the Confusion of an Exam
Medium
2.5K
35
company
Amazon
company
Facebook
company
Arcesium

A teacher is writing a test with n true/false questions, with 'T' denoting true and 'F' denoting false. He wants to confuse the students by maximizing the number of consecutive questions with the same answer (multiple trues or multiple falses in a row).

You are given a string answerKey, where answerKey[i] is the original answer to the ith question. In addition, you are given an integer k, the maximum number of times you may perform the following operation:

    Change the answer key for any question to 'T' or 'F' (i.e., set answerKey[i] to 'T' or 'F').

Return the maximum number of consecutive 'T's or 'F's in the answer key after performing the operation at most k times.

 

Example 1:

Input: answerKey = "TTFF", k = 2
Output: 4
Explanation: We can replace both the 'F's with 'T's to make answerKey = "TTTT".
There are four consecutive 'T's.

Example 2:

Input: answerKey = "TFFT", k = 1
Output: 3
Explanation: We can replace the first 'T' with an 'F' to make answerKey = "FFFT".
Alternatively, we can replace the second 'T' with an 'F' to make answerKey = "TFFF".
In both cases, there are three consecutive 'F's.

Example 3:

Input: answerKey = "TTFTTFTT", k = 1
Output: 5
Explanation: We can replace the first 'F' to make answerKey = "TTTTTFTT"
Alternatively, we can replace the second 'F' to make answerKey = "TTFTTTTT". 
In both cases, there are five consecutive 'T's.

 

Constraints:

    n == answerKey.length
    1 <= n <= 5 * 104
    answerKey[i] is either 'T' or 'F'
    1 <= k <= n

Accepted
85.2K
Submissions
126.2K
Acceptance Rate
67.5%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (49)
Similar Questions
Longest Substring with At Most K Distinct Characters
Medium
Longest Repeating Character Replacement
Medium
Max Consecutive Ones III
Medium
Minimum Number of Days to Make m Bouquets
Medium
Longest Nice Subarray
Medium
Related Topics
String
Binary Search
Sliding Window
Prefix Sum
*/

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int max_consecutive_answers = 0;
        map<char, int> count;

        for(int ind = 0; ind < answerKey.size(); ind++)
        {
            count[answerKey[ind]]++;
            int min_cho = min(count['T'], count['F']);

            if(min_cho <= k)
                max_consecutive_answers++;
            else
                count[answerKey[ind - max_consecutive_answers]]--;
        }

        return max_consecutive_answers;
    }
};