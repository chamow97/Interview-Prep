class Solution {
public:
    int longestWPI(vector<int>& hours) {
        unordered_map<int, int> m;
        int ans = 0;
        int total = 0;
        for(int i = 0; i < hours.size(); i++) {
            if(hours[i] > 8) {
                ans += 1;
            } else {
                ans -= 1;
            }
            if(ans > 0) {
                total = max(total, i + 1);
            } else {
                if(m.find(ans) == m.end()) {
                    m[ans] = i;
                }
                if(m.find(ans - 1) != m.end()) {
                    total = max(total, i - m[ans - 1]);
                }
            }
        }
        return total;
    }
};
