class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int i = 0;
        int n = A.size();
        while(i < n && A[i] < 0) {
            i++;
        }
        vector<int> ans;
        int j = i - 1;
        while(i < n && j >= 0) {
            while(i < n && j >= 0 && ((A[i] * A[i]) <= (A[j] * A[j]))) {
                ans.push_back(A[i] * A[i]);
                i++;
            }
            while(i < n && j >= 0 && ((A[j] * A[j]) <= (A[i] * A[i]))) {
                ans.push_back(A[j] * A[j]);
                j--;
            }
        }
        while(i < n) {
            ans.push_back(A[i] * A[i]);
            i++;
        }
        while(j >= 0) {
            ans.push_back(A[j] * A[j]);
            j--;
        }
        return ans;
    }
};
