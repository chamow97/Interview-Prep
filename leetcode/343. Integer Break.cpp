class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(60, 0);
        dp[1] = 0;
        dp[2] = 1;
        dp[3] = 2;
        for(int i = 4; i <= 58; i++) {
            for(int j = i - 1; j >= 2; j--) {
                dp[i] = max((i - j) * (j), max(dp[i], (i - j) * dp[j]));
            }
        }
        return dp[n];
    }
};
