class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int i = 0, j = 0;
        int n = A.size();
        int m = B.size();
        vector< vector<int> > ans;
        while(i < n && j < m) {
            if(B[j][1] < A[i][0]) {
                j++;
            } else if(A[i][1] < B[j][0]) {
                i++;
            } else {
                ans.push_back({max(A[i][0], B[j][0]), min(A[i][1], B[j][1])});
                if(A[i][1] < B[j][1]) {
                    i++;
                } else {
                    j++;
                }
            }
        }
        return ans;
    }
};
