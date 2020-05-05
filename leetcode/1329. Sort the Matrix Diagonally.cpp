class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        // left to right diagonal
        for(int i = 0; i < m; i++) {
            int k = 0, j = i;
            multiset<int> ms;
            while(k < n && j < m) {
                ms.insert(mat[k][j]);
                k++;
                j++;
            }
            k = 0, j = i;
            while(!ms.empty()) {
                int val = *ms.begin();
                mat[k][j] = val;
                ms.erase(ms.begin());
                k++;
                j++;
            }
        }
        for(int i = 1; i < n; i++) {
            int k = 0, j = i;
            multiset<int> ms;
            while(j < n && k < m) {
                ms.insert(mat[j][k]);
                k++;
                j++;
            }
            k = 0, j = i;
            while(!ms.empty()) {
                int val = *ms.begin();
                mat[j][k] = val;
                ms.erase(ms.begin());
                k++;
                j++;
            }
        }
        return mat;        
    }
};
