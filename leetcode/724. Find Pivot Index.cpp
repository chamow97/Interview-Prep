class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int currSum = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum -= nums[i];
            if(sum == currSum) {
                return i;
            }
            currSum += nums[i];
        }
        return -1;
    }
};
