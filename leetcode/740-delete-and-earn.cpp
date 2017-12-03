class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        //dp solution
        vector<int> frequency(10010, 0);
        for(auto i : nums)
        {
            frequency[i]++;
        }
        vector<int> dp(10010, 0);
        dp[0] = 0;
        dp[1] = frequency[1];
        dp[2] = max(dp[1], dp[0] + (frequency[2] * 2));
        for(int i = 3; i <= 10000; i++)
        {
            dp[i] = max(dp[i-1], dp[i-2] + (frequency[i] * i));
        }
        return dp[10000];
        
    }
};