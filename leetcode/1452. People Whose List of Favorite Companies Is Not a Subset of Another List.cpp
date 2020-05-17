class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        vector<int> ans;
        unordered_map<string, set<int> > m;
        for(int i = 0; i < favoriteCompanies.size(); i++) {
            for(auto j : favoriteCompanies[i]) {
                m[j].insert(i);
            }
        }
        for(int i = 0; i < favoriteCompanies.size(); i++) {
            unordered_map<int, int> m1;
            for(auto j : favoriteCompanies[i]) {
                for(auto k : m[j]) {
                    m1[k]++;
                }
            }
            bool possible = true;
            for(auto k : m1) {
                if(k.first != i && k.second >= favoriteCompanies[i].size()) {
                    possible = false;
                    break;
                }
            }
            if(possible) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
