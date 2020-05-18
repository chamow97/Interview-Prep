class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int curr = 0;
        for(auto i : nums) {
            if(i == 1) {
                curr++;
            } else {
                ans = max(ans, curr);
                curr = 0;
            }
        }
        ans = max(ans, curr);
        return ans;
    }
};
