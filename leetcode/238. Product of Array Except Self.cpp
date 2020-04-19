class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int fromB = 1, fromE = 1;
        int n = nums.size();
        vector< int > result(n, 1);
        for(int i = 0; i < n; i++) {
            result[i] *= fromB;
            fromB *= nums[i];
        }
        for(int i = n - 1; i >= 0; i--) {
            result[i] *= fromE;
            fromE *= nums[i];
        }
        return result;
    }
};
