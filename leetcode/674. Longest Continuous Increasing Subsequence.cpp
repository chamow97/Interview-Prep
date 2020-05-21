class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ans = 1;
        int i = 0, j = 1;
        int n = nums.size();
        if(n == 0) {
            return 0;
        }
        while(j < n) {
            while(j < n && nums[j] > nums[j - 1]) {
                j++;
            }
            ans = max(ans, j - i);
            i = j;
            j = i + 1;
        }
        return ans;
    }
};
