class MinStack {
public:
    /** initialize your data structure here. */
    stack< pair<int, int> > s;
    int minimum;
    MinStack() {
        while(!s.empty()) {
            s.pop();
        }
        minimum = INT_MAX;
    }
    
    void push(int x) {
        if(s.empty()) {
            minimum = x;
        } else {
            minimum = min(x, s.top().second);
        }
        s.push(make_pair(x, minimum));
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
