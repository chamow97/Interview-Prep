class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        multiset<int> ms;
        for(auto i : s) {
            ms.insert(i);
        }
        int ans = 0;
        for(auto i : g) {
            if(ms.lower_bound(i) != ms.end()) {
                ans++;
                ms.erase(ms.lower_bound(i));
            } else {
                break;
            }
        }
        return ans;
    }
};
