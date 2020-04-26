class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if(n <= 3) {
            return accumulate(nums.begin(), nums.end(), 0);
        }
        int currBest = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < n - 2; i++) {
            int j = i + 1, k = n - 1;
            while(j < k) {
                int currSum = nums[i] + nums[j] + nums[k];
                if(abs(target - currBest) > abs(target - currSum)) {
                    currBest = currSum;
                }
                if(currBest == target) {
                    return currBest;
                }
                if(currSum > target) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return currBest;
    }
};
