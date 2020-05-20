class Solution {
public:
    int dfs(int i, int j, vector< vector<int> > &grid) {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[i].size() || grid[i][j] <= 0) {
            return 0;
        }
        grid[i][j] = -grid[i][j];
        int currMax = max(dfs(i + 1, j, grid), max(dfs(i, j + 1, grid), max(dfs(i - 1, j, grid), dfs(i, j - 1, grid))));
        grid[i][j] = -grid[i][j];
        return currMax + grid[i][j];
        
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int maxVal = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                if(grid[i][j] != 0) {
                    maxVal = max(maxVal, dfs(i, j, grid));
                }
            }
        }
        return maxVal;
    }
};
