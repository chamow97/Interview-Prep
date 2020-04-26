class Solution {
public:
    void recurse(int begin, vector<int> &nums, map< vector<int>, bool > &result) {
        if(begin >= nums.size() - 1) {
            result[nums] = true;
            return;
        }
        for(int i = begin; i < nums.size(); i++) {
            if(i != begin && nums[i] == nums[begin]) {
                continue;
            }
            swap(nums[i], nums[begin]);
            recurse(begin + 1, nums, result);
            swap(nums[i], nums[begin]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        map< vector<int>, bool > result;
        recurse(0, nums, result);
        vector< vector<int> > finalResult;
        for(auto i : result) {
            finalResult.push_back(i.first);
        }
        return finalResult;
    }
};
