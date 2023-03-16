/*
382. Linked List Random Node
Medium
2.8K
667
company
Google

Given a singly linked list, return a random node's value from the linked list. Each node must have the same probability of being chosen.

Implement the Solution class:

    Solution(ListNode head) Initializes the object with the head of the singly-linked list head.
    int getRandom() Chooses a node randomly from the list and returns its value. All the nodes of the list should be equally likely to be chosen.

 

Example 1:

Input
["Solution", "getRandom", "getRandom", "getRandom", "getRandom", "getRandom"]
[[[1, 2, 3]], [], [], [], [], []]
Output
[null, 1, 3, 2, 2, 3]

Explanation
Solution solution = new Solution([1, 2, 3]);
solution.getRandom(); // return 1
solution.getRandom(); // return 3
solution.getRandom(); // return 2
solution.getRandom(); // return 2
solution.getRandom(); // return 3
// getRandom() should return either 1, 2, or 3 randomly. Each element should have equal probability of returning.

 

Constraints:

    The number of nodes in the linked list will be in the range [1, 104].
    -104 <= Node.val <= 104
    At most 104 calls will be made to getRandom.

 

Follow up:

    What if the linked list is extremely large and its length is unknown to you?
    Could you solve this efficiently without using extra space?

Accepted
222.1K
Submissions
353.9K
Acceptance Rate
62.8%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (47)
Similar Questions
Random Pick Index
Medium
Related Topics
Linked List
Math
Reservoir Sampling
Randomized

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
    vector<int> node_val;
    Solution(ListNode* head) {
        while(head)
        {
            node_val.push_back(head->val);
            head = head->next;
        }
    }
    
    int getRandom() {
        return node_val[(rand()%node_val.size())];
    }
};
/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */