class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int len = cost.size();
        if(len == 1)
        {
            return cost[0];
        }
        if(len == 2)
        {
            return min(cost[0], cost[1]);
        }
        vector<int> dp(len+10,0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < len; i++)
        {
            dp[i] = min(dp[i-2] , dp[i-1]) + cost[i];
        }
        
        int minimum = min(dp[len-2], dp[len-1]);
        fill(dp.begin(), dp.end(),0);
        dp[1] = cost[1];
        dp[2] = cost[2] + cost[0];
        for(int i = 3; i < len; i++)
        {
            dp[i] = min(dp[i-2] , dp[i-1]) + cost[i];
        }
        minimum = min(minimum, min(dp[len-2], dp[len-1]));
        return minimum;
    }
};