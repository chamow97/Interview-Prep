class Solution {
public:
    int solve(int n, int m, vector< vector< vector<int> > > &dp, int r, int c1, int c2, vector< vector<int> > &grid) {
        if(r >= n) {
            return 0;
        }
        if(dp[r][c1][c2] != 0) {
            return dp[r][c1][c2];
        }
        int maxValue = 0;
        int currVal = c1 == c2 ? grid[r][c1] : grid[r][c1] + grid[r][c2];
        for(int i = -1; i <= 1; i++) {
            for(int j = -1; j <= 1; j++) {
                int nC1 = c1 + i;
                int nC2 = c2 + j;
                if(nC1 >= 0 && nC1 < m && nC2 >= 0 && nC2 < m) {
                    maxValue = max(maxValue, solve(n, m, dp, r + 1, nC1, nC2, grid) + currVal);
                }
            }
        }
        dp[r][c1][c2] = maxValue;
        return maxValue;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector< vector< vector<int> > > dp(n, vector<vector<int>>(m, vector<int>(m, 0)));
        return solve(n, m, dp, 0, 0, m - 1, grid);
    }
};
