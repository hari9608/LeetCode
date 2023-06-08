/*
234. Palindrome Linked List
Easy
14.1K
772
company
Amazon
company
Apple
company
Microsoft

Given the head of a singly linked list, return true if it is a
palindrome
or false otherwise.

 

Example 1:

Input: head = [1,2,2,1]
Output: true

Example 2:

Input: head = [1,2]
Output: false

 

Constraints:

    The number of nodes in the list is in the range [1, 105].
    0 <= Node.val <= 9

 
Follow up: Could you do it in O(n) time and O(1) space?
Accepted
1.5M
Submissions
2.9M
Acceptance Rate
50.4%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (93)
Similar Questions
Palindrome Number
Easy
Valid Palindrome
Easy
Reverse Linked List
Easy
Maximum Twin Sum of a Linked List
Medium
Related Topics
Linked List
Two Pointers
Stack
Recursion
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
    bool isPalindrome(ListNode* head) {
        ListNode* temp_head = head;
        stack<int> palindrome;
        while(temp_head) 
        {
            palindrome.push(temp_head->val);
            temp_head = temp_head->next;
        }

        while(head && palindrome.top() == head->val)
        {
            palindrome.pop();
            head = head->next;
        }

        return palindrome.empty();
    }
};