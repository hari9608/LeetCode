/*
346. Moving Average from Data Stream
Easy
1.5K
152
company
Spotify
company
Facebook
company
Amazon

Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

Implement the MovingAverage class:

    MovingAverage(int size) Initializes the object with the size of the window size.
    double next(int val) Returns the moving average of the last size values of the stream.

 

Example 1:

Input
["MovingAverage", "next", "next", "next", "next"]
[[3], [1], [10], [3], [5]]
Output
[null, 1.0, 5.5, 4.66667, 6.0]

Explanation
MovingAverage movingAverage = new MovingAverage(3);
movingAverage.next(1); // return 1.0 = 1 / 1
movingAverage.next(10); // return 5.5 = (1 + 10) / 2
movingAverage.next(3); // return 4.66667 = (1 + 10 + 3) / 3
movingAverage.next(5); // return 6.0 = (10 + 3 + 5) / 3

 

Constraints:

    1 <= size <= 1000
    -105 <= val <= 105
    At most 104 calls will be made to next.

Accepted
311.2K
Submissions
403.4K
Acceptance Rate
77.1%
Seen this question in a real interview before?
1/4
Yes
No
Discussion (4)
Similar Questions
K Radius Subarray Averages
Medium
Related Topics
Array
Design
Queue
Data Stream
*/
class MovingAverage {
private:
    queue<int> data;
    double sum;
    int len;
public:
    MovingAverage(int size) {
        sum = 0;
        len = size;
    }
    
    double next(int val) {
        sum += val;
        data.push(val);
        if(data.size() > len){
            sum -= data.front();
            data.pop();
        }
        return sum/data.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */