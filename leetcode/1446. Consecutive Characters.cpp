class Solution {
public:
    int maxPower(string s) {
        vector<int> ans(s.length(), 1);
        for(int i = 1; i < s.length(); i++) {
            if(s[i] == s[i - 1]) {
                ans[i] = ans[i - 1] + 1;
            } else {
                ans[i] = 1;
            }
        }
        return *max_element(ans.begin(), ans.end());
    }
};
