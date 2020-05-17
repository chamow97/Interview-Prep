class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        set<string> s;
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                int GCD = __gcd(i, j);
                s.insert(to_string(i / GCD) + "/" + to_string(j / GCD));
            }
        }
        vector<string> ans;
        for(auto i : s) {
            ans.push_back(i);
        }
        return ans;
    }
};
