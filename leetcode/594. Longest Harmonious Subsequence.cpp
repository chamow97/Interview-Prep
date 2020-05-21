class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, j = 1, k = 0;
        int ans = 0;
        int n = nums.size();
        while(j < n) {
            while(j < n && nums[j] == nums[i]) {
                j++;
            }
            k = j;
            if(j < n && nums[j] == nums[i] + 1) {
                while(j < n && nums[j] == nums[i] + 1) {
                    j++;
                }
                ans = max(ans, j - i);
            }
            i = k;
            j = i + 1;
        }
        return ans;
    }
};
