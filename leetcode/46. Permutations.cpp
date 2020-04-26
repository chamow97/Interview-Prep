class Solution {
public:
    void recurse(int begin, vector<int> &nums, vector< vector<int> > &result) {
        if(begin >= nums.size()) {
            result.push_back(nums);
            return;
        }
        for(int i = begin; i < nums.size(); i++) {
            swap(nums[i], nums[begin]);
            recurse(begin + 1, nums, result);
            swap(nums[i], nums[begin]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector< vector<int> > result;
        recurse(0, nums, result);
        return result;
    }
};
