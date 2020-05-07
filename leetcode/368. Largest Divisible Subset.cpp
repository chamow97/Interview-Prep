class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) {
            return {};
        }
        sort(nums.begin(), nums.end());
        vector<int> index(n, -1);
        vector<int> subset(n, 1);
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] % nums[j] == 0) {
                    if(subset[j] + 1 > subset[i]) {
                        subset[i] = subset[j] + 1;
                        index[i] = j;
                    }
                }
            }
        }
        int maxIndex = 0;
        int maxValue = 0;
        for(int i = 0; i < n; i++) {
            if(maxValue < subset[i]) {
                maxValue = subset[i];
                maxIndex = i;
            }
        }
        vector<int> ans;
        while(maxIndex != -1) {
            ans.push_back(nums[maxIndex]);
            maxIndex = index[maxIndex];
        }
        return ans;
    }
};
