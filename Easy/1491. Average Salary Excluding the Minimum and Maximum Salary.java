/*
1491. Average Salary Excluding the Minimum and Maximum Salary
Easy
2.1K
177
company
Amazon
Netsuite

You are given an array of unique integers salary where salary[i] is the salary of the ith employee.

Return the average salary of employees excluding the minimum and maximum salary. Answers within 10-5 of the actual answer will be accepted.

 

Example 1:

Input: salary = [4000,3000,1000,2000]
Output: 2500.00000
Explanation: Minimum salary and maximum salary are 1000 and 4000 respectively.
Average salary excluding minimum and maximum salary is (2000+3000) / 2 = 2500

Example 2:

Input: salary = [1000,2000,3000]
Output: 2000.00000
Explanation: Minimum salary and maximum salary are 1000 and 3000 respectively.
Average salary excluding minimum and maximum salary is (2000) / 1 = 2000

 

Constraints:

    3 <= salary.length <= 100
    1000 <= salary[i] <= 106
    All the integers of salary are unique.

Accepted
306.1K
Submissions
481.6K
Acceptance Rate
63.6%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (64)
Related Topics
Array
Sorting
*/
class Solution {
    public double average(int[] salary) {
        int salary_len = salary.length;
        int min_salary = Integer.MAX_VALUE;
        int max_salary = Integer.MIN_VALUE;
        double total_salary = 0; 

        for(int i = 0; i < salary_len; i++)
        {
            min_salary = salary[i] < min_salary ? salary[i] : min_salary;
            max_salary = salary[i] > max_salary ? salary[i] : max_salary;
            total_salary = total_salary + salary[i];
        }

        total_salary = total_salary - min_salary - max_salary;

        return total_salary / (salary_len - 2);
    }
}