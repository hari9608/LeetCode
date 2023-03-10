class MyCircularQueue {
private:
    vector<int> my_circular_queue;
    int head;
    int tail;
    int size;
public:
    MyCircularQueue(int k) {
        my_circular_queue.resize(k);
        head = -1;
        tail = -1;
        size = k;
    }
    
    bool enQueue(int value) {
        if(isFull()) return false;
        if(isEmpty()) head = 0;
        tail = (tail + 1) % size;
        my_circular_queue[tail] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) return false;
        if(head == tail) head = tail = -1;
        else head = (head + 1) % size;
        return true;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return my_circular_queue[head];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return my_circular_queue[tail];
    }
    
    bool isEmpty() {
        return head == -1;
    }
    
    bool isFull() {
        return (tail + 1) % size == head;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
