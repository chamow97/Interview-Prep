class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, string> m;
        set<string> s;
        for(int i = 0; i < paths.size(); i++) {
            m[paths[i][0]] = paths[i][1];
            s.insert(paths[i][0]);
            s.insert(paths[i][1]);
        }
        string ans = "";
        for(auto i : s) {
            if(m.find(i) == m.end()) {
                ans = i;
            }
        }
        return ans;
    }
};
