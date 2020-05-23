class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for(auto i : s) {
            m[i]++;
        }
        set< pair<int, char>,greater< pair<int, char> > > ss;
        for(auto i : m) {
            
            ss.insert({i.second, i.first});
        }
        string ans = "";
        for(auto i : ss) {
            for(int j = 0; j < i.first; j++) {
                ans += i.second;
            }
        }
        return ans;
    }
};
