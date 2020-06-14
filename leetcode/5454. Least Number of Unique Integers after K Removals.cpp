class Solution {
public:
    static bool myFunc(pair<int, int> &a, pair<int, int> &b) {
        return a.second < b.second;
    }
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        for(auto i : arr) {
            m[i]++;
        }
        vector< pair<int, int> > p;
        for(auto i : m) {
            p.push_back({i.first, i.second});
        }
        sort(p.begin(), p.end(), myFunc);
        for(auto i : p) {
            int maxPossible = min(i.second, k);
            m[i.first] -= maxPossible;
            k -= maxPossible;
        }
        int ans = 0;
        for(auto i : m) {
            if(i.second > 0) {
                ans++;
            }
        }
        return ans;
    }
};
