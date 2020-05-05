class Solution {
public:
    int MOD = 1000000007;;
    int solve(int d, int f, int target, vector< vector<int> > &dp) {
        if(d < 0 || target < 0 || (d * f) < target) {
            return 0;
        }
        if(d == 0 && target == 0) {
            dp[d][target] = 1;
            return dp[d][target];
        }
        if(dp[d][target] != -1) {
            return dp[d][target];
        }
        int currentPossibility = 0;
        for(int i = 1; i <= f; i++) {
            currentPossibility = (currentPossibility + solve(d - 1, f, target - i, dp)) % MOD;
        }
        dp[d][target] = currentPossibility;
        return dp[d][target];
    }
    int numRollsToTarget(int d, int f, int target) {
        vector< vector<int> > dp(d + 1, vector<int>(target + 1, -1));
        return solve(d, f, target, dp);
    }
};
