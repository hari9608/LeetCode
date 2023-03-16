/*
167. Two Sum II - Input Array Is Sorted
Medium
9.1K
1.2K
company
Amazon
company
Bloomberg
company
Adobe

Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.

 

Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

Example 2:

Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].

Example 3:

Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].

 

Constraints:

    2 <= numbers.length <= 3 * 104
    -1000 <= numbers[i] <= 1000
    numbers is sorted in non-decreasing order.
    -1000 <= target <= 1000
    The tests are generated such that there is exactly one solution.

Accepted
1.4M
Submissions
2.3M
Acceptance Rate
60.0%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (43)
Similar Questions
Two Sum
Easy
Two Sum IV - Input is a BST
Easy
Two Sum Less Than K
Easy
Related Topics
Array
Two Pointers
Binary Search

*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> ans(2);
        int len = numbers.size();
        int ans1=0, ans2=len-1;
        int sum=0;
        while(ans1<ans2){
            sum = numbers[ans1] + numbers[ans2];
                if(sum == target){
                    ans[0] = ans1+1;
                    ans[1] = ans2+1;
                    break;
                }
                else if(sum > target){
                    ans2--;
                }
                else{
                    ans1++;
                }
            }
        return ans;
    }
};