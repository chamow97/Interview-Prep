class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) {
            return 0;
        }
        vector<int> dp(n, 1);
        vector<int> result(n, 1);
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[j] < nums[i]) {
                    if(dp[i] < dp[j] + 1) {
                        dp[i] = dp[j] + 1;
                        result[i] = result[j];
                    } else if(dp[i] == dp[j] + 1) {
                        result[i] += result[j];
                    }
                }
            }
        }
        int maxi = *max_element(dp.begin(), dp.end());
        int maxResult = 0;
        for(int i = 0; i < n; i++) {
            if(dp[i] == maxi) {
                maxResult += result[i];
            }
        }
        return maxResult;
    }
};
