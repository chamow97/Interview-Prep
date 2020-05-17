class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        int n = S.length();
        vector<int> ans(n);
        int last = -100000;
        for(int i = 0; i < n; i++) {
            if(S[i] == C) {
                last = i;
            }
            ans[i] = (i - last);
        }
        last = 100000;
        for(int i = n - 1; i >= 0; i--) {
            if(S[i] == C) {
                last = i;
            }
            ans[i] = min(ans[i], last - i);
        }
        return ans;
    }
};
