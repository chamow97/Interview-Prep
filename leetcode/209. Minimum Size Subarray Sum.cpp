class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        int ans = n + 1;
        if(n > 0) {
            int currSum = 0;
            currSum = nums[0];
            int i = 0, j = 0;
            while(i <= j && j < n) {
                if(currSum >= s) {
                    ans = min(ans, j - i + 1);
                    currSum -= nums[i];
                    i++;
                    if(i > j) {
                        j = i;
                        if(j < n) {
                            currSum = nums[i];
                        }
                    }
                } else {
                    j++;
                    if(j < n) {
                        currSum += nums[j];
                    }
                }
            }
        }
        if(ans == n + 1) {
            ans = 0;
        }
        return ans;
    }
};
