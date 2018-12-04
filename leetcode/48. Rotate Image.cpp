class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //transpose
        int n = matrix.size();
        int i, j;
        for(i = 0; i < n; i++)
        {
            for(j = i; j < n; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        //mirror
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n / 2; j++)
            {
                swap(matrix[i][j], matrix[i][n - j - 1]);
            }
        }
        // return matrix;
    }
};