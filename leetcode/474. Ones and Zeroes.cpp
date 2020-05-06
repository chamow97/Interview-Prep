class Solution {
public:
    int solve(vector< pair<int, int> > &arr, int index, int zero, int one, vector< vector< vector<int> > > &dp) {
        if(index < 0 || index >= arr.size()) {
            return 0;
        }
        if(dp[index][zero][one] != -1) {
            return dp[index][zero][one];
        }
        if((zero - arr[index].first) < 0 || (one - arr[index].second) < 0) {
            dp[index][zero][one] = solve(arr, index - 1, zero, one, dp);
            return dp[index][zero][one];
        }
        int currValue = max(solve(arr, index - 1, zero, one, dp), 1 + solve(arr, index - 1, zero - arr[index].first, one - arr[index].second, dp));
        dp[index][zero][one] = currValue;
        return dp[index][zero][one];
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        vector< pair<int, int> > arr(len);
        vector< vector< vector<int> > > dp(len + 1, vector< vector<int> > (m + 1, vector<int>(n + 1, -1)));
        for(int i = 0; i < strs.size(); i++) {
            int zero = 0, one = 0;
            for(auto j : strs[i]) {
                if(j == '0') {
                    zero++;
                } else {
                    one++;
                }
            }
            arr[i].first = zero;
            arr[i].second = one;
        }
        return solve(arr, len - 1, m, n, dp);
    }
};
