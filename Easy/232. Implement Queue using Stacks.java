/*
232. Implement Queue using Stacks
Easy
6.1K
356
company
Amazon
company
Microsoft
company
Goldman Sachs

Implement a first in first out (FIFO) queue using only two stacks. The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

Implement the MyQueue class:

    void push(int x) Pushes element x to the back of the queue.
    int pop() Removes the element from the front of the queue and returns it.
    int peek() Returns the element at the front of the queue.
    boolean empty() Returns true if the queue is empty, false otherwise.

Notes:

    You must use only standard operations of a stack, which means only push to top, peek/pop from top, size, and is empty operations are valid.
    Depending on your language, the stack may not be supported natively. You may simulate a stack using a list or deque (double-ended queue) as long as you use only a stack's standard operations.

 

Example 1:

Input
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 1, 1, false]

Explanation
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false

 

Constraints:

    1 <= x <= 9
    At most 100 calls will be made to push, pop, peek, and empty.
    All the calls to pop and peek are valid.

 

Follow-up: Can you implement the queue such that each operation is amortized O(1) time complexity? In other words, performing n operations will take overall O(n) time even if one of those operations may take longer.
Accepted
668.7K
Submissions
1.1M
Acceptance Rate
63.5%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (27)
Similar Questions
Implement Stack using Queues
Easy
Related Topics
Stack
Design
Queue
*/
class MyQueue {
    private Stack<Integer> stack_01 = new Stack<>();
    private Stack<Integer> stack_02 = new Stack<>();
    private int front = -1;
    public MyQueue() {
        
    }
    
    public void push(int x) {
        if(stack_01.empty())
            front = x;
        stack_01.push(x);
    }
    
    public int pop() {
        if(stack_02.isEmpty())
            while(!stack_01.isEmpty())
                stack_02.push(stack_01.pop());
        return stack_02.pop();
    }
    
    public int peek() {
        if(!stack_02.isEmpty())
            return stack_02.peek();
        return front;
    }
    
    public boolean empty() {
        return stack_01.isEmpty() && stack_02.isEmpty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */