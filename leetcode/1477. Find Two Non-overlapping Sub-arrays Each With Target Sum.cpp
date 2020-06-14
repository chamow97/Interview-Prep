class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        vector< pair<int, int> > p;
        int n = arr.size();
        map<int, int> m;
        m[0] = -1;
        for(int i = 1; i < arr.size(); i++) {
            arr[i] += arr[i - 1];
        }
        for(int i = 0; i < arr.size(); i++) {
            if(m.find(arr[i] - target) != m.end()) {
                p.push_back({m[arr[i] - target] + 1, i});
            }
            m[arr[i]] = i;
        }
        // all are same values
        if(p.size() < 2) {
            return -1;
        }
        int INF = 1e8 + 100;
        vector<int> pref(n, INF);
        vector<int> suff(n, INF);
        for(int i = 0; i < p.size(); i++) {
            // cout << p[i].first << ' ' << p[i].second << '\n';
            pref[p[i].second] = (p[i].second - p[i].first + 1); 
            suff[p[i].first] = (p[i].second - p[i].first + 1);
        }
        for(int i = 1; i < n; i++) {
            pref[i] = min(pref[i], pref[i - 1]);
        }
        for(int i = n - 2; i >= 0; i--) {
            suff[i] = min(suff[i], suff[i + 1]);
        }
        int ans = INF;
        for(int i = 0; i < n - 1; i++) {
            ans = min(ans, pref[i] + suff[i + 1]);
        }
        if(ans >= INF) {
            return -1;
        }
        return ans;
    }
};
