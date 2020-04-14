class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        // lets have a zero which is 0 if balanced, < 0 if there are more 1s than 0s and vice versa
        m[0] = -1;
        int zero = 0;
        int n = nums.size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 0) {
                zero++;
            } else {
                zero--;
            }
            if(m.find(zero) == m.end()) {
                m[zero] = i;
            }
            ans = max(ans, i - m[zero]);
        }
        return ans;
    }
};
