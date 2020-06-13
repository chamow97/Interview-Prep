class Solution {
public:
    vector<int> s;
    Solution(vector<int>& w) {
        for(auto i : w) {
            if(s.empty()) {
                s.push_back(i);
            } else {
                s.push_back(s.back() + i);
            }
        }
    }
    
    int pickIndex() {
        int m = s.back();
        int r = rand() % m;
        return upper_bound(s.begin(), s.end(), r) - s.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
