class Solution {
public:
    int smallestRangeI(vector<int>& A, int k) {
        sort(A.begin(), A.end());
        int n = A.size();
        A[0] += k;
        A[n - 1] -= k;
        int ans = A[n - 1] - A[0];
        if(ans < 0)
        {
        	ans = 0;
        }
        return ans;
    }
};