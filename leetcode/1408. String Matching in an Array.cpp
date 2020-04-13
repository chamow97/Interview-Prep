class Solution {
public:
    vector<string> stringMatching(vector<string>& str) {
        int n = str.size();
        set<string> ans;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j) {
                    int pos = str[i].find(str[j]);
                    if(pos != -1) {
                        ans.insert(str[j]);
                    }
                }
            }
        }
        vector< string > total;
        for(auto i : ans) {
            total.push_back(i);
        }
        return total;
    }
};
