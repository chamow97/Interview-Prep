class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        if(A.size() < 3) {
            return 0;
        }
        int dp[2] = {0};
        dp[0] = 0;
        dp[1] = 0;
        if(A[2] -  A[1] == A[1] - A[0]) {
            dp[0] = 1;
        }
        int result = dp[0];
        for(int i = 3; i < n; i++) {
            dp[1] = 0;
            if(A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                dp[1] = dp[0] + 1;
            }
            result += dp[1];
            dp[0] = dp[1];
        }
        return result;
    }
};
