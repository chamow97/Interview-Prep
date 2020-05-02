class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0, n = nums.size();
        for(int i = 2; i < n; i++) {
            if(nums[i] == nums[i - 2 - count]) {
                count++;
            } else {
                nums[i - count] = nums[i];
            }
        }
        return n - count;
    }
};
