class RecentCounter {
public:
    queue<int> s;
    RecentCounter() {
        while(!s.empty()) {
            s.pop();
        }
    }
    
    int ping(int t) {
        while(s.size() != 0 && s.front() < (t - 3000)) {
            s.pop();
        }
        s.push(t);
        return s.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
