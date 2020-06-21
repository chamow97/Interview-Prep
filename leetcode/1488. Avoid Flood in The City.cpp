class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        set<int> s;
        unordered_map<int, int> m;
        int n = rains.size();
        vector<int> ans(n, -1);
        for(int i = 0; i < n; i++) {
            if(rains[i] == 0) {
                s.insert(i);
                ans[i] = 1;
            } else {
                if(m.find(rains[i]) != m.end()) {
                    auto it = s.lower_bound(m[rains[i]]);
                    if(it == s.end()) {
                        return {};
                    }
                    int dryDay = *it;
                    ans[dryDay] = rains[i];
                    s.erase(it);
                }
                m[rains[i]] = i;
            }
        }
        return ans;
    }
};
