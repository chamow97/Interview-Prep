class Solution {
public:
    bool isPossible;
    bool solve(int index, vector<int> &nums, int sum, vector<int> &dp) {
        if(sum < 0) {
            return false;
        }
        if(index < 0) {
            return false;
        }
        if(sum == 0) {
            return true;
        }
        if(dp[sum] != -1) {
            return dp[sum];
        }
        bool currValue = solve(index - 1, nums, sum - nums[index], dp) || solve(index - 1, nums, sum, dp);
        dp[sum] = currValue;
        return dp[sum];
    }
    bool canPartition(vector<int>& nums) {
        isPossible = false;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2) {
            return false;
        }
        vector< int > dp((sum / 2) + 1, -1);
        return solve(nums.size() - 1, nums, sum / 2, dp);
    }
};
