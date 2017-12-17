class Solution {

public:
    
    int countCornerRectangles(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int total = 0;
        for(int i = 0; i < col; i++)
        {
            for(int j = i+1; j < col; j++)
            {
                int current = 0;
                for(int k = 0; k < row; k++)
                {
                    if(grid[k][i] == 1 && grid[k][j] == 1)
                    {
                        ++current;
                    }
                }
                if(current >= 2)
                {
                    total += ((current * (current - 1))/2);
                }
            }
        }
        return total;
    }
};