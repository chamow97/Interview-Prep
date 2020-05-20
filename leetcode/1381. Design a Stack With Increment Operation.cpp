class CustomStack {
public:
    int n;
    vector<int> inc;
    stack<int> s;
    CustomStack(int maxSize) {
        n = maxSize;
        inc.resize(n, 0);
        while(!s.empty()) {
            s.pop();
        }
    }
    
    void push(int x) {
        if(s.size() < n) {
            s.push(x);
        }
    }
    
    int pop() {
        if(s.empty()) {
            return -1;
        }
        int currTop = s.top();
        s.pop();
        currTop += inc[s.size()];
        if(s.size() > 0) {
            inc[s.size() - 1] += inc[s.size()];
        }
        inc[s.size()] = 0;
        return currTop;
    }
    
    void increment(int k, int val) {
        if(s.size() > 0)
        inc[min(k - 1, (int)s.size() - 1)] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
