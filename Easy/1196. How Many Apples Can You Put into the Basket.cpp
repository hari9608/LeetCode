/*
1196. How Many Apples Can You Put into the Basket
Easy
192
15
Virtu Financial

You have some apples and a basket that can carry up to 5000 units of weight.

Given an integer array weight where weight[i] is the weight of the ith apple, return the maximum number of apples you can put in the basket.

 

Example 1:

Input: weight = [100,200,150,1000]
Output: 4
Explanation: All 4 apples can be carried by the basket since their sum of weights is 1450.

Example 2:

Input: weight = [900,950,800,1000,700,800]
Output: 5
Explanation: The sum of weights of the 6 apples exceeds 5000 so we choose any 5 of them.

 

Constraints:

    1 <= weight.length <= 103
    1 <= weight[i] <= 103

Accepted
26.4K
Submissions
39.5K
Acceptance Rate
66.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (0)
Related Topics
Array
Greedy
Sorting
*/
class Solution {
public:
    int maxNumberOfApples(vector<int>& weight) {
        sort(weight.begin(), weight.end());

        int balance = 5000;
        int ind = 0;

        while(ind < weight.size() && balance >= weight[ind])     
            balance -= weight[ind++];

        return ind;
    }
};