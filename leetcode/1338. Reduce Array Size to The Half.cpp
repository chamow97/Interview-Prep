class Solution {
public:
    int minSetSize(vector<int>& arr) {
        multiset< pair<int, int>, greater< pair<int, int> > > ms;
        unordered_map<int, int> mp;
        for(int i = 0; i < arr.size(); i++) {
            mp[arr[i]]++;
        }
        for(auto i : mp) {
            ms.insert({i.second, i.first});
        }
        int ans = 0;
        int n = arr.size();
        while(ms.size() && n > (arr.size() / 2)) {
            pair<int, int> it = *ms.begin();
            ms.erase(ms.begin());
            n -= it.first;
            ans++;
        }
        return ans;
    }
};
