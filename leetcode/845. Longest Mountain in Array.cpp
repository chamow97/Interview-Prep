class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size();
        int i = 1;
        int increasing = 0, decreasing = 0;
        int ans = 0;
        while(i < n) {
            while(i < n && A[i - 1] < A[i]) {
                ++increasing;
                i++;
            }
            while(i < n && A[i - 1] > A[i]) {
                ++decreasing;
                i++;
            }
            if(increasing > 0 && decreasing > 0) {
                ans = max(ans, decreasing + increasing + 1);
            }
            while(i < n && A[i - 1] == A[i]) {
                i++;
            }
            increasing = 0;
            decreasing = 0;
        }
        return ans;
    }
};
