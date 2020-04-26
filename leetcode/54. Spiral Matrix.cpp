class Solution {
public:
    vector<int> result;
    void solve(vector< vector<int> > matrix, int stRow, int endRow, int stCol, int endCol) {
        if(stRow > endRow || stCol > endCol) {
            return;
        }
        // left to right
        for(int i = stCol; i <= endCol; i++) {
            result.push_back(matrix[stRow][i]);
        }
        // top to bottom
        for(int i = stRow + 1; i < endRow; i++) {
            result.push_back(matrix[i][endCol]);
        }
        // right to left
        if(endRow != stRow) {
            for(int i = endCol; i >= stCol; i--) {
                result.push_back(matrix[endRow][i]);
            }   
        }
        // bottom to top
        if(endCol != stCol) {
            for(int i = endRow - 1; i > stRow; i--) {
                result.push_back(matrix[i][stCol]);
            }
        }
        solve(matrix, stRow + 1, endRow - 1, stCol + 1, endCol - 1);
    } 
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        result.resize(0);
        int rows = matrix.size();
        if(rows == 0) {
            return result;
        }
        int cols = matrix[0].size();
        if(cols == 0) {
            return result;
        }
        solve(matrix, 0, rows - 1, 0, cols - 1);
        return result;
    }
};
