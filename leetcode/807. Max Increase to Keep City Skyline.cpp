class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int sum = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[i].size(); j++)
            {
                int max1 = 0;
                for(int k = 0; k < grid.size(); k++)
                {
                    max1 = max(max1, grid[k][j]);
                }
                int max2 = 0;
                for(int k = 0; k < grid[i].size(); k++)
                {
                    max2 = max(max2, grid[i][k]);
                }
                int minimum = min(max1, max2);
                if(grid[i][j] < minimum)
                {
                    sum += (minimum - grid[i][j]);
                }
            }
        }
        return sum;
    }
};