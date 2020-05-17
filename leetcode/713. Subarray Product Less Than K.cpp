class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        long long prod = 1;
        int i = 0, j = 0;
        int ans = 0;
        int n = nums.size();
        while(j < n) {
            prod *= nums[j];
            while(i <= j && prod >= k) {
                prod /= nums[i];
                i++;
            }
            ans += (j - i + 1);
            j++;
        }
        cout << ans;
        return ans;
    }
};
