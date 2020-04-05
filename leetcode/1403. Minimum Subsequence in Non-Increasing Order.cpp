class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans;
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }
        int j = n - 1;
        int currSum = 0;
        while(j >= 0 && currSum <= sum) {
            currSum += nums[j];
            sum -= nums[j];
            ans.push_back(nums[j]);
            j--;
        } 
        return ans;
    }
};
