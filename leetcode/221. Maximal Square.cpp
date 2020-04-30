class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        if(n == 0) {
            return 0;
        }
        int m = matrix[0].size();
        int maxSize = 0;
        vector< vector<int> > dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(matrix[i - 1][j - 1] == '0') {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
                }
                maxSize = max(maxSize, dp[i][j]);
            }
        }
        return maxSize * maxSize;
    }
};
