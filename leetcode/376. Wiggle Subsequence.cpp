class Solution {
public:
    // Uncomment below O(n ^ 2) solution
    // int solve(int index, int isIncreasing, vector<int> &nums, vector< vector<int> > &dp) {
    //     if(index < 0) {
    //         return 0;
    //     }
    //     if(dp[index][isIncreasing] != -1) {
    //         return dp[index][isIncreasing];
    //     }
    //     if(isIncreasing == 0) {
    //         int currMax = 0;
    //         for(int i = 0; i < index; i++) {
    //             if(nums[i] < nums[index]) {
    //                 currMax = max(currMax, 1 + solve(i, 1 - isIncreasing, nums, dp));
    //             }
    //         }
    //         dp[index][isIncreasing] = currMax;
    //         return dp[index][isIncreasing];
    //     } else {
    //         int currMax = 0;
    //         for(int i = 0; i < index; i++) {
    //             if(nums[i] > nums[index]) {
    //                 currMax = max(currMax, 1 + solve(i, 1 - isIncreasing, nums, dp));
    //             }
    //         }
    //         dp[index][isIncreasing] = currMax;
    //         return dp[index][isIncreasing];
    //     }
    // }
    // int wiggleMaxLength(vector<int>& nums) {
    //     vector< vector<int> > dp(nums.size(), vector<int>(3, -1));
    //     // Uncomment this for O(n ^ 2) solution
    //     if(nums.size() == 0) {
    //         return 0;
    //     }
    //     return 1 + max(solve(nums.size() - 1, 0, nums, dp), solve(nums.size() - 1, 1, nums, dp));
    // }
    
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 0) {
            return 0;
        }
        int goingUp = 1, goingDown = 1;
        //O(n) solution
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > nums[i - 1]) {
                goingUp = goingDown + 1;
            } else if(nums[i] < nums[i - 1]) {
                goingDown = goingUp + 1;
            }
        }
        return max(goingUp, goingDown);
    }
};
