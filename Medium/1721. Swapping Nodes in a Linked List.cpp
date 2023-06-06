/*
1721. Swapping Nodes in a Linked List
Medium
4.7K
158
company
Adobe
company
Amazon
company
Facebook

You are given the head of a linked list, and an integer k.

Return the head of the linked list after swapping the values of the kth node from the beginning and the kth node from the end (the list is 1-indexed).

 

Example 1:

Input: head = [1,2,3,4,5], k = 2
Output: [1,4,3,2,5]

Example 2:

Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
Output: [7,9,6,6,8,7,3,0,9,5]

 

Constraints:

    The number of nodes in the list is n.
    1 <= k <= n <= 105
    0 <= Node.val <= 100

Accepted
275.9K
Submissions
400.5K
Acceptance Rate
68.9%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (36)
Similar Questions
Remove Nth Node From End of List
Medium
Swap Nodes in Pairs
Medium
Reverse Nodes in k-Group
Hard
Related Topics
Linked List
Two Pointers
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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* swap_nodes = head;
        ListNode* begin = nullptr;
        ListNode* end = nullptr;
        int list_position = 0;
        
        while(head)
        {
            list_position++;
            
            if(end)
                end = end->next;
            
            if(list_position == k)
            {
                begin = head;
                end = swap_nodes;
            }

            head = head->next;
        }

        swap(begin->val, end->val);

        return swap_nodes;
    }
};