/*
445. Add Two Numbers II
Medium
5.5K
278
company
Amazon
company
Bloomberg
company
Apple

You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

Example 1:

Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]

Example 2:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]

Example 3:

Input: l1 = [0], l2 = [0]
Output: [0]

 

Constraints:

    The number of nodes in each linked list is in the range [1, 100].
    0 <= Node.val <= 9
    It is guaranteed that the list represents a number that does not have leading zeros.

 

Follow up: Could you solve it without reversing the input lists?
Accepted
434.2K
Submissions
711.9K
Acceptance Rate
61.0%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (40)
Similar Questions
Add Two Numbers
Medium
Add Two Polynomials Represented as Linked Lists
Medium
Related Topics
Linked List
Math
Stack
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> n1;
        stack<int> n2;

        while (l1 != nullptr) 
        {
            n1.push(l1->val);
            l1 = l1->next;
        }
        while (l2 != nullptr) 
        {
            n2.push(l2->val);
            l2 = l2->next;
        }

        int total_sum = 0;
        int carry = 0;
        ListNode* add_two_numbers = new ListNode();

        while (!n1.empty() || !n2.empty()) 
        {
            if (!n1.empty()) 
            {
                total_sum += n1.top();
                n1.pop();
            }
            if (!n2.empty()) 
            {
                total_sum += n2.top();
                n2.pop();
            }

            add_two_numbers->val = total_sum % 10;
            carry = total_sum / 10;
            ListNode* newNode = new ListNode(carry);
            newNode->next = add_two_numbers;
            add_two_numbers = newNode;
            total_sum = carry;
        }

        return carry == 0 ? add_two_numbers->next : add_two_numbers;
    }
};