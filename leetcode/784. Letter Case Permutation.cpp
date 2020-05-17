class Solution {
public:
    vector<string> ans;
    void solve(int index, string S, string now) {
        if(index >= S.length()) {
            ans.push_back(now);
            return;
        }
        if(S[index] >= '0' && S[index] <= '9') {
            solve(index + 1, S, now + S[index]);
        } else {
            if(S[index] >= 'a' && S[index] <= 'z') {
                solve(index + 1, S, now + S[index]);
                solve(index + 1, S, now + (char)(S[index] - 32));
            } else {
                solve(index + 1, S, now + S[index]);
                solve(index + 1, S, now + (char)(S[index] + 32));
            }
        }
    }
    vector<string> letterCasePermutation(string S) {
        ans.resize(0);
        solve(0, S, "");
        return ans;
    }
};
