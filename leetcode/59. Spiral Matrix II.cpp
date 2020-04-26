class Solution {
public:
    vector< vector<int> > result;
    void solve(int stRow, int endRow, int stCol, int endCol, int CurrVal) {
        if(stRow > endRow || stCol > endCol) {
            return;
        }
        // left to right
        for(int i = stCol; i <= endCol; i++) {
            result[stRow][i] = (CurrVal++);
        }
        // top to bottom
        for(int i = stRow + 1; i < endRow; i++) {
            result[i][endCol] = (CurrVal++);
        }
        // right to left
        if(endRow != stRow) {
            for(int i = endCol; i >= stCol; i--) {
                result[endRow][i] = (CurrVal++);
            }   
        }
        // bottom to top
        if(endCol != stCol) {
            for(int i = endRow - 1; i > stRow; i--) {
                result[i][stCol] = (CurrVal++);
            }
        }
        solve(stRow + 1, endRow - 1, stCol + 1, endCol - 1, CurrVal);
    } 
    vector<vector<int>> generateMatrix(int n) {
        result.resize(n, vector<int>(n, 0));
        solve(0, n - 1, 0, n - 1, 1);
        return result;
    }
};
