class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> prefixSumCount;
        int result = 0;
        int currSum = 0;
        prefixSumCount[0] = 1;
        for(int i = 0; i < nums.size(); i++) {
            currSum += nums[i];
            result += prefixSumCount[currSum - k];
            prefixSumCount[currSum]++;
        }
        return result;
    }
};
