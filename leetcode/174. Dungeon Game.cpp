class Solution {
public:
    int n, m;
    int solve(int i, int j, vector< vector<int> > &dp, vector< vector<int> > &grid) {
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        if(i == n - 1 && j == m - 1) {
            int curr = 0;
            if(grid[i][j] < 0) {
                curr = abs(grid[i][j]) + 1;
            } else {
                curr = 1;
            }
            dp[i][j] = curr;
            return dp[i][j];
        }
        if(i == n - 1) {
            int curr = 0;
            if(grid[i][j] >= solve(i, j + 1, dp, grid)) {
                curr = 1;
            } else {
                curr = solve(i, j + 1, dp, grid) - grid[i][j];
            }
            dp[i][j] = curr;
            return dp[i][j];
        }
        if(j == m - 1) {
            int curr = 0;
            if(grid[i][j] >= solve(i + 1, j, dp, grid)) {
                curr = 1;
            } else {
                curr = solve(i + 1, j, dp, grid) - grid[i][j];
            }
            dp[i][j] = curr;
            return dp[i][j];
        }
        int curr = min(solve(i + 1, j, dp, grid), solve(i, j + 1, dp, grid)) - grid[i][j];
        if(curr <= 0) {
            curr = 1;
        }
        dp[i][j] = curr;
        return dp[i][j];
    }
    
    int calculateMinimumHP(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        vector< vector<int> > dp(n + 1, vector<int>(m + 1, -1));
        return solve(0, 0, dp, grid);
    }
};
