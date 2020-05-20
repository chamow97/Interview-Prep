class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& grid, int n, int m) {
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0) {
            return 0;
        }
        int maxVal = 0;
        grid[i][j] = 0;
        maxVal = dfs(i + 1, j, grid, n, m) + dfs(i - 1, j, grid, n, m) + dfs(i, j + 1, grid, n, m) + dfs(i, j - 1, grid, n, m);
        return 1 + maxVal;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxVal = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j]) {
                    maxVal = max(maxVal, dfs(i, j, grid, n, m));
                }
            }
        }
        return maxVal;
    }
};
