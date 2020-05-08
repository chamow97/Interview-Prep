class Solution {
public:
    int ans;
    int solve(vector<int> &nums, int target, vector<int> &dp) {
        if(target == 0) {
            return 1;
        }
        if(dp[target] != -1) {
            return dp[target];
        }
        int currAns = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(target >= nums[i]) {
                currAns += solve(nums, target - nums[i], dp);
            }
        }
        dp[target] = currAns;
        return dp[target];
    }
    int combinationSum4(vector<int>& nums, int target) {
        ans = 0;
        vector<int> dp(target + 1, -1);
        return solve(nums, target, dp);
    }
};
