/*
7. Reverse Integer

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321

Example 2:

Input: x = -123
Output: -321

Example 3:

Input: x = 120
Output: 21

 
Constraints:

    -231 <= x <= 231 - 1

*/
class Solution {
public:
    int reverse(int x) {
        if(x>=INT_MAX || x<=INT_MIN) return 0;
        int neg = 0;
        if(x<0){
            neg=1;
            x = -x;
        }
        long int rev=0;
        while(x>0){
            rev = rev*10 + x%10;
            x /= 10; 
        }
        if(neg){
            return (-1 * rev < INT_MIN ? 0 : -rev);
        }
        else{
            return (rev>INT_MAX?0:rev);
        }
        return 0;
    }
};