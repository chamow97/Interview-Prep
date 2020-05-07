class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool initialValue = false;
        // first store the state of initial row
        for(int i = 0; i < matrix[0].size(); i++) {
            if(matrix[0][i] == 0) {
                initialValue = true;
            }
        }
        // go from first row
        for(int i = 1; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        // set all the rows
        for(int i = 1; i < matrix.size(); i++) {
            if(matrix[i][0] == 0) {
                for(int j = 0; j < matrix[0].size(); j++) {
                    matrix[i][j] = 0;
                }
            }
        }
        // set all the cols
        for(int j = 0; j < matrix[0].size(); j++) {
            if(matrix[0][j] == 0) {
                for(int i = 0; i < matrix.size(); i++) {
                    matrix[i][j] = 0;   
                }
            }
        }
        if(initialValue) {
            for(int i = 0; i < matrix[0].size(); i++) {
                matrix[0][i] = 0;
            }
        }
    }
};
