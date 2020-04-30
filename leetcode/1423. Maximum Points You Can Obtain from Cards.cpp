class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector<int> dp(k + 1, 0);
        int n = cardPoints.size();
        // store the best value by choosing i values from left
        for(int i = n - 1; i >= (n - k); i--) {
            dp[0] += cardPoints[i];
        }
        // from first start and subtract the extra value for each index from last
        for(int i = 1; i <= k; i++) {
            dp[i] = dp[i - 1] + cardPoints[i - 1] - cardPoints[n - k + i - 1];
        }
        int maxValue = 0;
        for(int i = 0; i <= k; i++) {
            maxValue = max(maxValue, dp[i]);
        }
        return maxValue;
    }
};
