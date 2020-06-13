class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> s;
    MyQueue() {
        while(!s.empty()) {
            s.pop();
        }
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if(s.empty()) {
            s.push(x);
            return;
        }
        int t = s.top();
        s.pop();
        push(x);
        s.push(t);
        return;
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int val = s.top();
        s.pop();
        return val;
    }
    
    /** Get the front element. */
    int peek() {
        return s.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
