/*
703. Kth Largest Element in a Stream
Easy
4.7K
2.8K
company
Amazon
company
Facebook
company
Adobe

Design a class to find the kth largest element in a stream. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Implement KthLargest class:

    KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
    int add(int val) Appends the integer val to the stream and returns the element representing the kth largest element in the stream.

 

Example 1:

Input
["KthLargest", "add", "add", "add", "add", "add"]
[[3, [4, 5, 8, 2]], [3], [5], [10], [9], [4]]
Output
[null, 4, 5, 5, 8, 8]

Explanation
KthLargest kthLargest = new KthLargest(3, [4, 5, 8, 2]);
kthLargest.add(3);   // return 4
kthLargest.add(5);   // return 5
kthLargest.add(10);  // return 5
kthLargest.add(9);   // return 8
kthLargest.add(4);   // return 8

 

Constraints:

    1 <= k <= 104
    0 <= nums.length <= 104
    -104 <= nums[i] <= 104
    -104 <= val <= 104
    At most 104 calls will be made to add.
    It is guaranteed that there will be at least k elements in the array when you search for the kth element.

Accepted
414.2K
Submissions
729.5K
Acceptance Rate
56.8%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (49)
Similar Questions
Kth Largest Element in an Array
Medium
Finding MK Average
Hard
Sequentially Ordinal Rank Tracker
Hard
Related Topics
Tree
Design
Binary Search Tree
Heap (Priority Queue)
Binary Tree
Data Stream
*/
class KthLargest {
public:
    
    priority_queue<int, vector<int>, greater<int>> pr_que;
    int size;
    
    KthLargest(int k, vector<int>& nums) {
        size = k;
        for(int x : nums) 
        {
            pr_que.push(x);
            if(pr_que.size() > size)    pr_que.pop();
        }
    }
    
    int add(int val) {
        pr_que.push(val);
        if(pr_que.size() > size)   pr_que.pop();
        return pr_que.top();
    }
};