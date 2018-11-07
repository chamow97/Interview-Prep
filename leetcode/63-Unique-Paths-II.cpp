class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dp[n + 1][m + 1];
        if(grid[0][0] == 1)
        {
            return 0;
        }
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= m; j++)
            {
                dp[i][j] = 0;
            }
        }
        for(int i = 1; i <= n; i++)
        {
            if(grid[i-1][0] != 1)
            dp[i][1] = 1;
            else
            {
                break;
            }
        }
        for(int i = 1; i <= m; i++)
        {
            if(grid[0][i-1] != 1)
            dp[1][i] = 1;
            else
                break;
        }
        for(int i = 2; i <= n; i++)
        {
            for(int j = 2; j <= m; j++)
            {
                if(grid[i-1][j-1] != 1)
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[n][m];
    }
};