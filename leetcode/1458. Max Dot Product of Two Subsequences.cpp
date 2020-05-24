class Solution {
public:
    int solve(int i, int j, vector< vector<int> > &dp, vector<int>& nums1, vector<int>& nums2) {
        if(i < 0 || j < 0) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        int currProd = nums1[i] * nums2[j];
        int currMax = max(currProd + solve(i - 1, j - 1, dp, nums1, nums2), max(solve(i, j - 1, dp, nums1, nums2), solve(i - 1, j, dp, nums1, nums2)));
        dp[i][j] = currMax;
        return dp[i][j];
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector< vector<int> > dp(n + 1, vector<int>(m + 1, -1));
        int maxi = solve(n - 1, m - 1, dp, nums1, nums2);
        if(maxi == 0) {
            int currMax = INT_MIN;
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < m; j++) {
                    currMax = max(currMax, nums1[i] * nums2[j]);
                }
            }
            return currMax;
        }
        return maxi;
    }
};
