class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n1 = -1, n2 = -1, n3 = -1;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] == 0) {
                nums[++n3] = 2;
                nums[++n2] = 1;
                nums[++n1] = 0;
            } else if(nums[i] == 1) {
                nums[++n3] = 2;
                nums[++n2] = 1;
            } else {
                nums[++n3] = 2;
            }
        }
    }
};
