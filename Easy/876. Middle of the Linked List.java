/*
876. Middle of the Linked List
Easy
9.6K
284
company
Amazon
company
Apple
company
Adobe

Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.

 

Example 1:

Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.

Example 2:

Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.

 

Constraints:

    The number of nodes in the list is in the range [1, 100].
    1 <= Node.val <= 100

Accepted
1.4M
Submissions
1.8M
Acceptance Rate
76.0%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (55)
Similar Questions
Delete the Middle Node of a Linked List
Medium
Maximum Twin Sum of a Linked List
Medium
Related Topics
Linked List
Two Pointers
*/
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode middleNode(ListNode head) {
        ListNode middle_node = head;

        while(head != null)
        {
            head = head.next;
            if(head != null)
            {
                head = head.next;
                middle_node = middle_node.next;
            }
        }

        return middle_node;
    }
}

// middle_node act as a slow pointer
// head act as a fast pointer